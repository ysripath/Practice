#include <iostream>
#include <string>
#include <cstring>

using namespace std;


string convert(string s, int numRows) {
        
        int l = s.size();
        char* buf = new char[l];
        strcpy(buf,s.c_str());
        if (numRows<=1)
            return s;
        bool flag = true;
        
        int rowNum = 0;
        int k = 0;
        string* arr = new string[numRows];
        for (int i = 0; i < numRows; i++)
        {
            arr[i] = "";
        }
        int row = 0;
        while (k < l)
        {
            
                arr[row] += buf[k];
            
            k++;
            if (flag)
                row++;
            else
                row--;
            if (row == numRows) {
                row = numRows - 2;
                flag = false;
            }
            else if (row == -1) {
                row = 1;
                flag = true;
            }
                
        }
        string temp;
        for (int i = 0; i < numRows; i++)
        {
            if(arr[i].compare(""))
                temp += arr[i];
        }
        return temp;
}

int main()
{
	cout<<"Enter string and numRows\n";
	int N;
	string str;
	cin>>str>>N;
	string temp = convert(str,N);
	cout<<temp<<endl;
	return 0;
}
