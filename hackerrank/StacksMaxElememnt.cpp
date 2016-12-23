#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int N;
	cin>>N;
	int choice, data;
	stack<int> S;
	int max[100000] = { 0 };
	int tempM = -999;
	while(N != 0)
	{
		cin>>choice;
		switch(choice)
		{
			case 1: {cin>>data; 
				 tempM = max[S.size()];

				 S.push(data);
				 if (tempM >= data)
					max[S.size()] = tempM;
				 else
					max[S.size()] = data;
				 break;}
			case 2: { 	max[S.size()] = -1;
					S.pop();
				  
				 break;}
			case 3: { cout<<max[S.size()]<<endl; 
				 break;}
			default: { cout<<"Invalid query made\n"; break;}
		}
		N--;
	}
    return 0;
}

