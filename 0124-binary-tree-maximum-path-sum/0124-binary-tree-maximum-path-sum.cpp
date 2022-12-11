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
    int help(TreeNode* root , int &res )
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int left = help(root->left,res);
        int right = help(root->right,res);
        
        if(left<0)  left = 0;
        if(right<0) right = 0;
        res = max(res , left + right + root->val);
        
        return max(left,right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        int temp = help(root,res);
        return res;
    }
};