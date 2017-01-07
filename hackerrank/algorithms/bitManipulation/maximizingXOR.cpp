#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
/*
 * Complete the function below.
 */
int maxXor(int l, int r) {
    int max = -1;
    int R = (l<r)?r:l;
    int L = (l<r)?l:r;
    
    for (int i = L; i <= R; i++)
        {
        for (int j = L; j <= R; j++) {
            int temp = i^j;
            if (temp>max)
                max = temp;
        }
    }
    return max;
}

int main() {
    int res;
    int _l;
    cin >> _l;
    
    int _r;
    cin >> _r;
    
    res = maxXor(_l, _r);
    cout << res;
    
    return 0;
}

