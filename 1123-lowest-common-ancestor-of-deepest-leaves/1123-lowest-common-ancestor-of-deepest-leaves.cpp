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
    TreeNode* help(TreeNode* root, int height)
    {
        if(root == NULL)    return NULL;
        if(height == 1)     return root;
        
        TreeNode* left = help(root->left,height-1);
        TreeNode* right = help(root->right,height-1);
        
        if(left != NULL && right == NULL)       return left;
        else if(left == NULL && right != NULL)  return right;
        else if(left != NULL && right != NULL)  return root;
        else                                    return NULL;
    }
    int findHeight(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int left = findHeight(root->left);
        int right = findHeight(root->right);
        
        return max(left , right)+1;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int height = findHeight(root);
        return help(root,height);
    }
};