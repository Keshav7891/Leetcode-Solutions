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
    bool help(TreeNode* root1 , TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL)
        {
            return true;
        }
        else if(root1 == NULL && root2 != NULL)
        {
            return false;
        }
        else if(root1 != NULL && root2 == NULL)
        {
            return false;
        }
        
        if(root1->val != root2->val)
        {
            return false;
        }
        
        bool left = help(root1->left,root2->left);
        bool right = help(root1->right,root2->right);
        
        return left && right;
    }
    bool help1(TreeNode* root , TreeNode* subRoot)
    {
        if(root == NULL)
        {
            return false;
        }
        
        if(root->val == subRoot->val && help(root,subRoot) == true)
        {
            return true;
        }
        
        bool left = help1(root->left,subRoot);
        bool right = help1(root->right,subRoot);
        
        return left || right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return help1(root,subRoot);
    }
};