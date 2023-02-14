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
    TreeNode* help(TreeNode* root , int low , int high)
    {
        if(root == NULL)    return NULL;
        int curr = root->val;
        if(curr < low)  return help(root->right,low,high);
        if(curr > high) return help(root->left,low,high); 
        root->left = help(root->left,low,high);
        root->right = help(root->right,low,high);
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return help(root,low,high);
    }
};