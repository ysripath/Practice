#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{

  char* hexstring = "28d1eac9fff87918ff8792d4b1e61ee7b0467a55143a0276f06f6e2b012e88d3dbaefcf5b406c1386cab49e3a483b93e707465475077a1dcd853353c4839e5659ac1699e65f2e974b043e24e1f9a2ee417723526fcebd6e3289166ca02f356216347795d6e31c5674deb6271da793a0d85b6b6a297929d123d0f92a9435f40748a8bfb5a065f0304878ac0f4636a807ad380395328804ae57ffddf923a41ecc17deade04f073c57ac0f9c50042440f2e878a86863309055f41c91401412283dc992e91dc25e29d1898a7efe328e93173de4e64341bdf522991d8a37c81c249cd7f5fdf695b726fddfaa0863ec400a394ab79a87170332bf481987348522ec670";
/* const char *pos = hexstring;
    unsigned char val[sizeof(hexstring)];

   //   WARNING: no sanitization or error-checking whatsoever 
    for (size_t count = 0; count < sizeof val/sizeof *val; count++) {
        sscanf(pos, "%2hhx", &val[count]);
        pos += 2;
    }

    printf("0x");
    for(size_t count = 0; count < sizeof val/sizeof *val; count++)
        printf("%02x", val[count]);
    printf("\n");*/

//char *hexstring = "deadbeef10203040b00b1e50";
    int i;
    unsigned int bytearray[256];
    int str_len = strlen(hexstring);

    for (i = 0; i < (str_len / 2); i++) {
        sscanf(hexstring + 2*i, "%02x", &bytearray[i]);
        printf("bytearray %d: %02x\n", i, bytearray[i]);
    }


return 0;
}
