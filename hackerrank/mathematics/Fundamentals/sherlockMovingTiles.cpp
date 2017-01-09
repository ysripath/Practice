#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define y1 yy

using namespace std;

int x1, y1, X1, Y1, x2, y2, X2, Y2;
void initialize(int L)
{
	x1 = y1 = x2 = y2 = 0;
	X1 = X2 = Y1 = Y2 = L;
}
void move(int S1, int S2)
{
	x1+=S1;
	y1+=S1;
	X1+=S1;
	Y1+=S1;

	x2+=S2;
	y2+=S2;
	X2+=S2;
	Y2+=S2;
}

bool check (int q)
{
	cout<<"X1 Y1 "<<X1<<" "<<Y1<<" x2 y2 "<<x2<<" "<<y2<<endl<<"Q area ";
	cout<<(X1-x2)*(Y1-y2)<<endl;
	if (q == ((X1-x2)*(Y1-y2)))
		return true;
	else
		return false;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int L;
	long int S1, S2;
	int Q;
	int q;
	int t = 0;
	cin>>L>>S1>>S2>>Q;
//	int x1,y1,X1,Y1,x2,y2,X2,Y2;
	initialize(L);
	while (Q!=0)
	{
		cin>>q;
		if (q == L*L)
		{
			cout<<"0"<<endl;
			Q--;
			continue;
		}
		bool flag = true;
		while(flag)
		{
			move(S1,S2);
			if(check(q))
			{
				double t = ((sqrt(2)*X2)/S2);
				cout<<t<<endl;
				flag = false;
			}
		}
		initialize(L);
		Q--;
	}
	
    return 0;
}

