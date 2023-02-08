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
    bool res = true;
    int help(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int left = help(root->left);
        int right = help(root->right);
        
        int diff = abs(left - right);
        if(diff > 1)    res = false;
        
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        int ht = help(root);
        return res;
    }
};