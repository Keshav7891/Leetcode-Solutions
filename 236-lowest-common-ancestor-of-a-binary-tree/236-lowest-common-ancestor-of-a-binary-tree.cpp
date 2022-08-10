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
    TreeNode* help(TreeNode* root , TreeNode* p , TreeNode* q)
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(root==p || root==q)
        {
            return root;
        }
        
        TreeNode* left = help(root->left,p,q);
        TreeNode* right = help(root->right,p,q);
        
        if(left==NULL && right==NULL)
        {
            return NULL;
        }
        else if(left!=NULL && right==NULL)
        {
            return left;
        }
        else if(left==NULL && right!=NULL)
        {
            return right;
        }
        else
        {
            return root;
        }
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = help(root,p,q);
        return res;
    }
};