#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void solve(int px, int py, int qx, int qy, int* rx, int* ry)
{
	*rx = 2*qx - px;
	*ry = 2*qy - py;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int N;
	cin>>N;
	int px,py,qx,qy,rx,ry;
	while(N!=0)
	{
		
		N--;
		cin>>px>>py>>qx>>qy;
		solve(px,py,qx,qy,&rx, &ry);
		cout<<rx<<" "<<ry<<endl;
	}
    return 0;
}

