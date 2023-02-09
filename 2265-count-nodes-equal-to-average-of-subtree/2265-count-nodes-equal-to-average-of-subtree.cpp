/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = 0;
    pair<int,int> help(TreeNode* root)
    {
        if(root == NULL)
        {
            return {0,0};
        }
        
        pair<int,int> left = help(root->left);
        pair<int,int> right = help(root->right);
        
        int lsum = left.first;
        int rsum = right.first;
        
        int lc = left.second;
        int rc = right.second;
        
        int total = lsum + rsum + root->val;
        int count = lc + rc + 1;
        
        if(root->val == total/count)
        {
            res++;
        }
        
        return {total,count};
    }
    int averageOfSubtree(TreeNode* root) {
        help(root);
        return res;
    }
};