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
    int help(TreeNode* root , bool &res)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lh = 1 + help(root->left,res);
        int rh = 1 + help(root->right,res);
        if(abs(lh-rh)>1)
        {
            res=false;
        }
        
            return max(lh,rh);

    }
    bool isBalanced(TreeNode* root) {
        bool res = true;
        int temp = help(root,res);
        return res;
    }
};