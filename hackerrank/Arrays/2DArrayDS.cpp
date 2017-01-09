#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int MAX = -999;

void solve(int i, int j, vector< vector<int>> arr)
{
	int sum = 0;
	sum = arr[i][j] + arr[i][j + 1] + arr[i][j+2] \
		+ arr[i+1][j+1] + \
		arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
	if (sum > MAX)
		MAX = sum;
}

int main(){
    vector< vector<int> > arr(6,vector<int>(6));
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }

	for (int i = 0;  i<=3; i++)
		for (int j = 0; j <= 3; j++)
		{
			solve(i,j,arr);
		} 
	
	cout<<MAX<<endl;
    return 0;
}

