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
    int help(TreeNode* root , int &res)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int left_height = help(root->left,res);
        int right_height = help(root->right,res);
        
        int dia = left_height + right_height;
        res = max(res,dia);
        
        return max(left_height , right_height) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN;
        int ht = help(root,res);
        return res;
    }
};