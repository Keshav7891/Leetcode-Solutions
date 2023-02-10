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
    int trgt = -1;
    TreeNode* help(TreeNode* root)
    {
        if(root == NULL)
        {
            return NULL;
        }
        
        // if(root->left == NULL && root->right == NULL)
        // {
        //     if(root->val == trgt)
        //     {
        //         return NULL;
        //     }
        //     else
        //     {
        //         return root;
        //     }
        // }
        
        root->left = help(root->left);
        root->right = help(root->right);
        
        if(root->left == NULL && root->right == NULL && root->val == trgt)
        {
            return NULL;
        }
        
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        trgt = target;
        return help(root);
    }
};