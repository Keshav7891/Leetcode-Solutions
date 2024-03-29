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
    void help(TreeNode* root , vector<int>&nums)
    {
        if(root == NULL)
        {
            return ;
        }
        help(root->left,nums);
        help(root->right,nums);
        nums.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>nums;
        help(root,nums);
        return nums;
    }
};