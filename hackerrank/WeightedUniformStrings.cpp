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

unordered_map<int,bool> map1;

int getW(char c)
    {
    return ((int)c - 96);
}

void formMap(string s)
    {
    char* buf = new char[s.length()];
    strcpy(buf,s.c_str());
    char temp;
    int prevW;
    for (int i = 0; i < s.length(); i++)
        {
        
        if (i == 0)
            {
            int w = getW(buf[i]);
            map1.insert(make_pair(w,true));
            temp = buf[0];
            prevW = w;
        }
        else
            {
            if (temp == buf[i])
                {
                
                int w = getW(buf[i]);
                auto itr = map1.find(prevW + w);
                if (itr == map1.end()) {
                    map1.insert(make_pair(prevW+w,true));
                }
                prevW += w;
            }
            else
                {
                int w = getW(buf[i]);
                auto itr = map1.find(w);
                if (itr == map1.end()) {
                    map1.insert(make_pair(w,true));                    
                }
                temp = buf[i];
                prevW = w;
            }
        }
        
    }
    
}

int main(){
    string s;
    cin >> s;
    formMap(s);
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        int x;
        cin >> x;
        auto itr = map1.find(x);
        if (itr != map1.end())
            cout<<"Yes\n";
        else
            cout<<"No\n";
        // your code goes here
    }
    return 0;
}
