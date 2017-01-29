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

void roundOff(int grade)
    {
    int multiple = 35;
    while (multiple < grade)
        {
        multiple += 5;
    }
    if (multiple-grade < 3)
        cout<<multiple<<endl;
    else
        cout<<grade<<endl;
}
int main(){
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        int grade;
        cin >> grade;
        // your code goes here
        if (grade >= 38)
            {
            roundOff(grade);
        }
        else
            cout<<grade<<endl;
    }
    return 0;
}
