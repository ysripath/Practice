#include <vector>
#include <utility>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = INT_MIN;
    int x = 1;
	vector<pair<int, int>> visited;
	int tempH = 0;
	for (auto h : height) {
	    
		for (auto i : visited) {
		    if (tempH == 0)
		       {
		           tempH = min(h,i.second);
		       }
		    if (i.second < tempH)
		       continue;
			int b = x - i.first;
			int small;
			if (h < i.second)
				small = h;
			else
				small = i.second;
			if (b*small > max)
				max = b*small;
		}

		visited.push_back(make_pair(x++, h));

	}
	

	return max;
        
    }
};