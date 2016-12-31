#include <iostream>
#include <string>
#include <ctype.h>
#include <string.h>
using namespace std;

bool ipv4Flag = false;
bool ipv6Flag = false;

bool validDelimiter(char buf[])
{
	int len = strlen(buf);
	for (int i = 0; i < len; i++)
	{
		if (buf[i] == '.')
		{
			ipv4Flag = true;	
		}
		else if (buf[i] == ':')
		{
			ipv6Flag = true;
		}
	}
	if ((ipv4Flag && ipv6Flag) || (!ipv4Flag && !ipv6Flag)) // if non of the delimiter are present or both the delimiters are present
	{
		return false;
	}
	else// if (ipv4Flag || ipv6Flag)
	{
		return true;	
	}
}


bool validTokenIpv4(char* token)
{
	int len = strlen(token);
	for (int i = 0; i < len; i++)
	{
		if ((int)token[i] >= 48 && (int)token[i] <= 57)
			continue;
		else
			return false; // found non numeric character in one of the octects of IPv4 address
	}
	string tempStr(token);
	if (!(tempStr.compare("000")) || !(tempStr.compare("00")))
	{
		return false; // ipv4 cannot have 000 or 00 in an octect.
	}
	int temp = atoi(token);
	if ( (temp >= 0) && (temp <= 255))
		return true;
	else
		return false;
}

bool validipv4(string ip)
{
	int count = 0;
	char* token;
	char delim = '.';
	token = strtok((char*)ip.c_str(),".");
	while(token != NULL)
	{
		if (validTokenIpv4(token))
			token = strtok(NULL,".");
		else
			return false;
		count++;
	}
	if (count == 4)
		return true;
	else
		return false;
}

bool validTokenIpv6(char* token)
{
	int len = strlen(token);
        for (int i = 0; i < len; i++)
        {
                if (((int)token[i] >= 48 && (int)token[i] <= 57) || ((int)token[i] >= 65 && (int)token[i] <= 90)  || ((int)token[i] >= 97 && (int)token[i] <= 122))
                        continue;
                else
                        return false; // found special character in one of the octects of IPv6 address
        }
	string temp(token);
	if (!(temp.compare("0000")) || !(temp.compare("000")) || !(temp.compare("00")))
		return false;
	return true;
}
bool validipv6(string ip)
{
	int count = 0;
	char* token;
	token = strtok((char*)ip.c_str(),":");
	while(token != NULL)
	{
		if (validTokenIpv6(token))
			token = strtok(NULL,":");
		else
			return false;
		count++;
	}
	if (count == 8)
		return true;
	else
		return false;
}

string check(string ip)
{
	int ipSize = ip.size();
	char* buf = new char[ipSize];
	strcpy(buf,ip.c_str());

	// check for the delimiter of IPV4 adn IPV6
	if (validDelimiter(buf))
	{
		if (ipv4Flag)
		{
			if (validipv4(ip))
			{
				return string("IPv4");
			}
			else
			{
				return string("Neither");
			}
		}
		else
		{
			if (validipv6(ip))
			{
				return string("IPv6");
			}
			else
			{
				return string("Neither");
			}
		}
	}
	else
	{
		return string("Neither");
	}
}

int main()
{
	cout<<"Enter the IP address\n";
	string ip;
	cin>>ip;
	string res = check(ip);
	cout<<res<<endl;
	return 0;
}
