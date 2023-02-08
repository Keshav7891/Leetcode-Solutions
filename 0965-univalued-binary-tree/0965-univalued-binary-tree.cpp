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
    bool help(TreeNode* root , int &flag)
    {
        if(root == NULL)
        {
            return true;
        }
        
        if(flag == -1)
        {
            flag = root->val;
        }
        else 
        {
            if(flag != root->val)
            {
                return false;
            }
        }
        
        bool left = help(root->left,flag);
        bool right = help(root->right,flag);
        
        return left && right;
    }
    bool isUnivalTree(TreeNode* root) {
        int flag = -1;
        return help(root,flag);
    }
};