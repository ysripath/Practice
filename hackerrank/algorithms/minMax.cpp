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
void initialize(bool arr[])
    {
    for (int i = 0; i < 5; i++)
        arr[i] = false;
}

void solve(long int a,long int b,long int c, long int d, long int e) {
    bool arr[5] = {0};
    long int arr2[5] = {a,b,c,d,e};
    initialize(arr);
    int count = 0;
    long int MAX = LONG_MIN;
    long int MIN = LONG_MAX;
    while (count < 5) {
        arr[count] = true;
        long int sum = 0;
        for (int i = 0;  i < 5; i++) {
            if (i != count) {
                sum += arr2[i];
            }
        }
        if (sum < MIN)
            MIN = sum;
        if (sum > MAX)
            MAX = sum;
        initialize(arr);
        count++;
    }
    cout<<MIN<<" "<<MAX<<endl;
}


int main(){
    long int a;
    long int b;
    long int c;
    long int d;
    long int e;
    cin >> a >> b >> c >> d >> e;
    solve(a,b,c,d,e);
    return 0;
}
