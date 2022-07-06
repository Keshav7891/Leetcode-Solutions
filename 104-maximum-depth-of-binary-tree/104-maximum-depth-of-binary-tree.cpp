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
        if(root==NULL)
        {
            return 0;
        }
        int lh = 1 + help(root->left);
        int rh = 1 + help(root->right);
        return max(lh,rh);
    }
    int maxDepth(TreeNode* root) {
        int res = help(root);
        return res;
    }
};