#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int solve(int n)
    {
    int h = 1;
    bool flag = true;
    while (n > 0) {
        if (flag) {
            h*=2;
            flag = false;
        }
        else {
            h +=1;
            flag = true;
        }
        n--;        
    }
    return h;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout<<solve(n)<<endl;
    }
    return 0;
}
