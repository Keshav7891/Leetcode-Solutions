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
    void help(TreeNode* &curr , TreeNode* root)
    {
        if(root == NULL)
        {
            return ;
        }
        
        help(curr,root->left);
        TreeNode* temp = new TreeNode(root->val);
        curr->right = temp;
        curr = curr->right;
        help(curr,root->right); 
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *curr = new TreeNode(0);
        TreeNode *new_root = curr;
        help(curr,root);
        return new_root->right;
    }
};