#include <iostream>

using namespace std;


int main()
{
	int n = 9;
	int N = n;
	int cnt=1;
	while ( n > 0)
	{
		for (int i = 0; i <n; i++)
			cout<<" ";
		for (int j = 0; j < cnt; j++)
		{
			if (j == 0 || j == cnt-1 || cnt == N)
				cout<<cnt<<" ";
			else
				cout<<"  ";
		}
		for (int i = 0; i <n; i++)
                        cout<<" ";
		cout<<endl;
		cnt++;
		n--;
	}

	return 0;
}
