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
    int help(TreeNode* root)
    {
        if(root == NULL)
        {
            return INT_MAX;
        }
        
        if(root->left==NULL && root->right == NULL)
        {
            return 1;
        }
        
        int lh = help(root->left);
        int rh = help(root->right);
        
        return min(lh,rh)+1;
    }
    int minDepth(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        return help(root);
    }
};