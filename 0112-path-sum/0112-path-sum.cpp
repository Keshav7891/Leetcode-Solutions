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
    bool help(TreeNode* root , int path)
    {
        if(root == NULL)
        {
            return false;
        }
        
        if(root->left == NULL && root->right == NULL)
        {
            if(path - root->val == 0)
            {
                return true;
            }
        }
        
        bool left = help(root->left,path - root->val);
        bool right = help(root->right,path - root->val);
        
        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return help(root,targetSum);
    }
};