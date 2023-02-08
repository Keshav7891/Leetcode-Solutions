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
    string help(TreeNode* root)
    {
        if(root == NULL)
        {
            return "";
        }
        if(root->left == NULL && root->right == NULL)
        {
            return  to_string(root->val) ;
        }
        
        string left = help(root->left);
        string right = help(root->right);
        
        if(left == "" && right != "")
        {
            return to_string(root->val) + '(' + left +')' + '(' + right + ')';
        }
        else if(left != "" && right == "")
        {
            return to_string(root->val) + '(' + left +')';
        }
        else if(left == "" && right == "")
        {
            return to_string(root->val);
        }
        else
        {
            return to_string(root->val) + '(' + left +')' + '(' + right + ')';
        }
    }
    string tree2str(TreeNode* root) {
        string str =  help(root);
        return str;
    }
};