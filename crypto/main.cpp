#include <iostream>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/bio.h>
#include <fstream>
#include <string>
#include <streambuf>
#include <cstring>

void Base64Encode( const unsigned char* buffer, 
                   size_t length, 
                   char** base64Text) { 
  BIO *bio, *b64;
  BUF_MEM *bufferPtr;
  b64 = BIO_new(BIO_f_base64());
  bio = BIO_new(BIO_s_mem());
  bio = BIO_push(b64, bio);
  BIO_write(bio, buffer, length);
  BIO_flush(bio);
  BIO_get_mem_ptr(bio, &bufferPtr);
  BIO_set_close(bio, BIO_NOCLOSE);
  BIO_free_all(bio);
  *base64Text=(*bufferPtr).data;
}

RSA* createPrivateRSA(std::string key) {
  RSA *rsa = NULL;
  const char* c_string = key.c_str();
  BIO * keybio = BIO_new_mem_buf((void*)c_string, -1);
  if (keybio==NULL) {
      return 0;
  }
  rsa = PEM_read_bio_RSAPrivateKey(keybio, &rsa,NULL, NULL);
  return rsa;
}

bool RSASign( RSA* rsa, 
              const unsigned char* Msg, 
              size_t MsgLen,
              unsigned char** EncMsg, 
              size_t* MsgLenEnc) {
  EVP_MD_CTX* m_RSASignCtx = EVP_MD_CTX_create();
  EVP_PKEY* priKey  = EVP_PKEY_new();
  EVP_PKEY_assign_RSA(priKey, rsa);
  if (EVP_DigestSignInit(m_RSASignCtx,NULL, EVP_sha256(), NULL,priKey)<=0) {
      return false;
  }
  if (EVP_DigestSignUpdate(m_RSASignCtx, Msg, MsgLen) <= 0) {
      return false;
  }
  if (EVP_DigestSignFinal(m_RSASignCtx, NULL, MsgLenEnc) <=0) {
      return false;
  }
  *EncMsg = (unsigned char*)malloc(*MsgLenEnc);
  if (EVP_DigestSignFinal(m_RSASignCtx, *EncMsg, MsgLenEnc) <= 0) {
      return false;
  }
  EVP_MD_CTX_cleanup(m_RSASignCtx);
  return true;
}




// Verify


size_t calcDecodeLength(const char* b64input) {
  size_t len = strlen(b64input), padding = 0;
  if (b64input[len-1] == '=' && b64input[len-2] == '=') //last two chars are =
    padding = 2;
  else if (b64input[len-1] == '=') //last char is =
    padding = 1;
  return (len*3)/4 - padding;
}

void Base64Decode(char* b64message, unsigned char** buffer, size_t* length) {
  BIO *bio, *b64;
  int decodeLen = calcDecodeLength(b64message);
  *buffer = (unsigned char*)malloc(decodeLen + 1);
  (*buffer)[decodeLen] = '\0';
  bio = BIO_new_mem_buf(b64message, -1);
  b64 = BIO_new(BIO_f_base64());
  bio = BIO_push(b64, bio);
  *length = BIO_read(bio, *buffer, strlen(b64message));
  BIO_free_all(bio);
}

RSA* createPublicRSA(std::string key) {
  RSA *rsa = NULL;
  BIO *keybio;
  const char* c_string = key.c_str();
  keybio = BIO_new_mem_buf((void*)c_string, -1);
  if (keybio==NULL) {
      return 0;
  }
  rsa = PEM_read_bio_RSA_PUBKEY(keybio, &rsa,NULL, NULL);
  return rsa;
}


bool RSAVerifySignature( RSA* rsa, 
                         unsigned char* MsgHash, 
                         size_t MsgHashLen, 
                         const char* Msg, 
                         size_t MsgLen, 
                         bool* Authentic) {
  *Authentic = false;
  EVP_PKEY* pubKey  = EVP_PKEY_new();
  EVP_PKEY_assign_RSA(pubKey, rsa);
  EVP_MD_CTX* m_RSAVerifyCtx = EVP_MD_CTX_create();
  if (EVP_DigestVerifyInit(m_RSAVerifyCtx,NULL, EVP_sha256(),NULL,pubKey)<=0) {
    return false;
  }
  if (EVP_DigestVerifyUpdate(m_RSAVerifyCtx, Msg, MsgLen) <= 0) {
    return false;
  }
  int AuthStatus = EVP_DigestVerifyFinal(m_RSAVerifyCtx, MsgHash, MsgHashLen);
  if (AuthStatus==1) {
    *Authentic = true;
    EVP_MD_CTX_cleanup(m_RSAVerifyCtx);
    return true;
  } else if(AuthStatus==0){
    *Authentic = false;
    EVP_MD_CTX_cleanup(m_RSAVerifyCtx);
    return true;
  } else{
    *Authentic = false;
    EVP_MD_CTX_cleanup(m_RSAVerifyCtx);
    return false;
  }
}


bool verifySignature(std::string publicKey, std::string plainText, char* signatureBase64) {
  RSA* publicRSA = createPublicRSA(publicKey);
  unsigned char* encMessage;
  size_t encMessageLength;
  bool authentic;
  Base64Decode(signatureBase64, &encMessage, &encMessageLength);
  bool result = RSAVerifySignature(publicRSA, encMessage, encMessageLength, plainText.c_str(), plainText.length(), &authentic);
  return result & authentic;
}


std::string& fix_newlines(std::string& s)
{
    size_t start_pos = 0;
    while((start_pos = s.find("\\n", start_pos)) != std::string::npos) {
         s.replace(start_pos, 2, "\n");
         start_pos += 1;
    }
    return s;
}

int main()
{
	std::ifstream iF("message.txt");
	//iF.open();
  //std::string plainText = "9b27ea15; 0; ; 1; (Alice, 5000)\n";
	std::string plainText;// = "0; ; 1; (Alice, 5000)\n";
	getline(iF, plainText);
	plainText += "\n";	
  //std::string privateKey = "";

  //ifstream infile { "private.pem" };
   //std::string privateKey { istreambuf_iterator<char>(infile), istreambuf_iterator<char>() };

std::ifstream t("private.pem");
std::string privateKey((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());


  RSA* privateRSA = createPrivateRSA(privateKey);
  unsigned char* encMessage;
  char* base64Text; // = "fFZ5j4MEXF7eIKiWYpe+sE+sBQTy241Jy3lxZdNHqhdljA7vBNu2LZaDr8JfXIq7\npUqZSMDkO6KKhClDInnXbDkAq4F7WXu4EV4xQJUb+CX2foW0l/9lSdM64w1ui+jB\nSSmeTwlnqDaoSMbiQyzx5yFSZLGUCmWxdcPNIMzek4h8qOU0FNBGGEOqjNhP94/y\nmMYXxuRnZq4JtSEiKAKtasX7QOxWnLwYRifulQUNNwIOP2ro2VdXJYtH8UK9K0Sv\nu1CiOhM4IBBG1Q1o8BXe2VZGfix5OLCvB7Vu+MBpakqg9yC557aJLkoRVj+c39yD\nZOvgUbspUb37/1CsyaEL0w==\n";
 std::ifstream iS("sign.txt");
	std::string base64;
	getline(iS, base64);
	base64 = fix_newlines(base64);
	std::cout<<"Base - "<<base64<<std::endl;
	base64Text = (char*)base64.c_str();

// = "qXJKCyq95OEmB/L90jyY+ve3mJy3eeGiVeEaa1sBZoJeCuhVrHzXw3azPWvDQYxt\nPZz4QZynpiNewftHUkK+R52ZcIZ4Qzzvx3d6tjMUwiebuVYVLDDBvgsCBlx/94HI\naIN4Ngj8pTYHXdVxokrA32Yxz6PuFK2Xl+aqoDKvDckxhMX8KyRgaqc6W5Zq/+0t\ngcQOXcxTsDwp5AG0mOR1NyllKaCjjmpcdfQt3nhmrJq+TSzb++6KmcpUFqAR7pzM\npUVbvlxF1gb77sglhY3aYzbDXhBad5vYXiWJj0F3O5J3ZoVdHHjZNoHux5bUSRYq\n/oRmZ5BbtAh1SZjR709a0Q==\n";
	/*std::string tempS = "qXJKCyq95OEmB/L90jyY+ve3mJy3eeGiVeEaa1sBZoJeCuhVrHzXw3azPWvDQYxtPZz4QZynpiNewftHUkK+R52ZcIZ4Qzzvx3d6tjMUwiebuVYVLDDBvgsCBlx/94HIaIN4Ngj8pTYHXdVxokrA32Yxz6PuFK2Xl+aqoDKvDckxhMX8KyRgaqc6W5Zq/+0tgcQOXcxTsDwp5AG0mOR1NyllKaCjjmpcdfQt3nhmrJq+TSzb++6KmcpUFqAR7pzMpUVbvlxF1gb77sglhY3aYzbDXhBad5vYXiWJj0F3O5J3ZoVdHHjZNoHux5bUSRYq/oRmZ5BbtAh1SZjR709a0Q==";
	char base64Text[1000];
	strcpy(base64Text, tempS.c_str());*/

/* qXJKCyq95OEmB/L90jyY+ve3mJy3eeGiVeEaa1sBZoJeCuhVrHzXw3azPWvDQYxt
PZz4QZynpiNewftHUkK+R52ZcIZ4Qzzvx3d6tjMUwiebuVYVLDDBvgsCBlx/94HI
aIN4Ngj8pTYHXdVxokrA32Yxz6PuFK2Xl+aqoDKvDckxhMX8KyRgaqc6W5Zq/+0t
gcQOXcxTsDwp5AG0mOR1NyllKaCjjmpcdfQt3nhmrJq+TSzb++6KmcpUFqAR7pzM
pUVbvlxF1gb77sglhY3aYzbDXhBad5vYXiWJj0F3O5J3ZoVdHHjZNoHux5bUSRYq
/oRmZ5BbtAh1SZjR709a0Q==*/

// = "nLCn8A1gxJZoKO48sa0ieWGdCMsW5Vt0gXbJPyXVZuDAOmgsGcS8YhoSjvuEFegrtjUGEUbyJOigkCePa1ouBnWP8KdCeOWbx92aoVQfZ24NR6pM0mC0dcudYyzJM97qO7Y0NoW5QLPPNWEY13y+2lTVeiZ26uvfY8bLvAosouY36IRuxu4eH+E/5aYnvuA4UEz0yVaXWOj0gvuwzuGrLnDz8n7dKnQeHZzcqiaQ8WyFWoJy+bwgGHQwqdBWNl0yPwygu9E1quCyK1L+LGkpPT5j3mzR48ubXBw7I9BbYxYjfhjRt7iTKFTp+5UbUPOp2OsrvszkF/jNv9DjJ3igYA==";
  size_t encMessageLength;
  RSASign(privateRSA, (unsigned char*) plainText.c_str(), plainText.length(), &encMessage, &encMessageLength);
 // Base64Encode(encMessage, encMessageLength, &base64Text);
  	free(encMessage);
  //return base64Text;
	std::cout<<"Base64-> "<<base64Text<<"\n";

  std::ifstream t1("public.pem");
std::string publicKey((std::istreambuf_iterator<char>(t1)),
                 std::istreambuf_iterator<char>());

 if (verifySignature(publicKey, plainText, base64Text))
   std::cout<<"Verification OK\n";
 else 
  std::cout<<"Verification fail\n";
  return 0;
}	
