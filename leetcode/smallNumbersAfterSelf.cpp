class Solution {
public:
    int check(vector<int> nums, int k)
    {
        int count = 0;
        int temp = nums[k];
        int l = nums.size();
        
        for (int i = k; i < l; i++)
        {
            if (nums[i] < temp)
                count++;
        }
        return count;
    }
    int check2(vector<int> nums, int k,int v[])
    {
        int l = nums.size();
        int count = 0;
        int j = nums[k];
        for (int i = k; i <l; i++)
        {
            if (nums[i] < j)
            {
                count++;
                continue;
            }
            if (i != l-1)
            {
            int temp = nums[i+1] - nums[i];
            if (temp == 1 || temp == 0)
                return (v[i+1] + count);
            }
        }
        return count;
    }
    vector<int> countSmaller(vector<int>& nums) {
        
        int l = nums.size();
        int* v = new int[l];
        v[l-1] = 0;
        for (int i = l-2; i >=0; i--)
        {
            if (nums[i] > nums[i+1])
                v[i] = check2(nums,i,v);
            else
                {
                    int temp = check(nums, i);
                    v[i] = temp;
                }
        }
        vector<int> V;
        for (int i = 0; i < l; i++)
        {
            V.push_back(v[i]);
        }
        return V;
        
    }
};
