#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;

void display(int i)
{
	cout<<i;
}

void util(int* arr, int &l)
{
	int tempArr[10000] = {0};
	int tC = 1;
	int temp = -1;
	int count = -1;
	bool flag = false;
	for (int i = 1; i <= l; i++)
	{
		
		if (temp == -1)
		{
			temp = arr[i];
			count = 1;
			if (l == 1)
			{
				//cout<<count;
				tempArr[tC++] = count;
				//display(temp);
				tempArr[tC] = temp;
				for (int j = 1; j <= tC; j++)
		        		{
               				 arr[j] = tempArr[j];
        				}
        			l = tC;
	//			cout<<endl;
				return;
			}
		}
		else if (arr[i] == temp)
		{
			count++;

		}
		else
		{
			//cout<<count;
			tempArr[tC++] = count;
			//display(temp);
			tempArr[tC++] = temp;
			temp = arr[i];
			count = 1;	
			//flag = true;
		}
	}
	if (!flag)
	{
		 //cout<<count;
                        tempArr[tC++] = count;
                   //     display(temp);
                        tempArr[tC++] = temp;
                        
                        count = 1;
                        flag = true;
	}
//	cout<<endl;
	tC--;
	for (int i = 1; i <= tC; i++)
	{
		arr[i] = tempArr[i];
	}
	l = tC;
}


int main()
{

	int arr[10000] = {0};
	int N;
	cout<<"Enter N \n";
	cin>>N;
	if (N == 1)
		cout<<"1"<<endl;
	int l = 1;
	arr[1] = 1;
	N--;
	while (N > 0)
	{
	
			util(arr,l);
		N--;	
	}
	char buf[10];
	string s;
	ostringstream oss("");
	for (int i = 0; i < l; i++)
	{
		//strncpy(buf, sizeof(buf), "%d",arr[i+1]);
		//s = s + itoa(arr[i+1]);
		oss << arr[i+1];
	}
	//	cout<<s;
	string str = oss.str();
	cout<<str<<endl;
	return 0;
}
