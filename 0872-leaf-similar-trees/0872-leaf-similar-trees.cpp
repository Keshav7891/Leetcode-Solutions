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
    void help(TreeNode* root , vector<int>& nums)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->left == NULL && root->right == NULL)
        {
            nums.push_back(root->val);
        }
        help(root->left,nums);
        help(root->right,nums);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>nums1,nums2;
        help(root1,nums1);
        help(root2,nums2);
        if(nums1 == nums2)
        {
            return true;
        }
        return false;
    }
};