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
    int res = 0;
    void help(TreeNode* root , int steps , int right)
    {
        if(root == NULL)
        {
            return ;
        }
        res = max(res,steps);
        if(right == 1)
        {
            help(root->left,steps+1,0);
            help(root->right,1,1);
        }
        else
        {
            help(root->right,steps+1,1);
            help(root->left,1,0);
        }
    }
    int longestZigZag(TreeNode* root) {
        help(root,0,0);
        help(root,0,1);
        return res;
    }
};