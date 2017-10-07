/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int count;
    int arr[10000];
    Solution():count(0),arr{0}{}
    void util(TreeNode* root)
    {
        if (root == NULL)
            return;
        util(root->left);
        arr[count++] = root->val;
        util(root->right);
    }
    int utilDiff()
    {
        count--;
        int i = 0;
        int j = 1;
        int min = 999999;
        for (;j <= count; i++,j++)
        {
            if ((arr[j] - arr[i])  < min)
                min = arr[j] - arr[i];
        }
        return min;
    }
    int getMinimumDifference(TreeNode* root) {
        util(root);
        return utilDiff();
    }
};
