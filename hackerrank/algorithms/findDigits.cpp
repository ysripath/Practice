#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int check(int N)
    {
    int* arr = new int[10000000];
    int count = 0;
    if (N==0)
        return 0;
    if (N<10)
        return 1;
    int temp = N;
    int sampleTemp;
    
    while ( temp > 9)
        {
        int rem = temp % 10;
        arr[count++] = rem;
        temp = temp/10;
    }
    arr[count++] = temp;
    int aCount = 0;
    for (int i = 0; i < count; i++)
        {
        if (arr[i] == 0)
            continue;
        if (N%arr[i] == 0)
            aCount++;
    }
    return aCount;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout<<check(n)<<endl;
    }
    
    return 0;
}
