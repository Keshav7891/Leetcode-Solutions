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
    void help(TreeNode* root , int path)
    {
        if(root == NULL)
        {
            return;
        }
        
        if(root->left == NULL && root->right == NULL)
        {
            res = res + (path * 10 + root->val);
        }
        
        int curr = root->val;
        
        help(root->left,path*10 + curr);
        help(root->right,path*10 + curr);
    }
    int sumNumbers(TreeNode* root) {
        help(root,0);
        return res;
    }
};