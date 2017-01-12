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

unsigned long long check(unsigned long long x)
    {
    unsigned long long count = 0;
    for (unsigned long long i = 1; i < x; i++)
        {
        unsigned long long temp = i^x;
        if (temp>x)
            count++;
    }
    return count;
}

int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        unsigned long long x;
        cin >> x;
        // your code goes here
        cout<<check(x)<<endl;
    }
    return 0;
}

