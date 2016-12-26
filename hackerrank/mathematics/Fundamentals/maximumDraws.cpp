#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin>>N;
	int pair;
	while(N != 0)
	{
		cin>>pair;
		cout<<pair+1<<endl;
		N--;
	}
    return 0;
}

