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
    TreeNode* help(int low , int high , vector<int>&nums)
    {
        if(low>high)
        {
            return NULL;
        }
        int mid = (low+high)/2;
        TreeNode* node = new TreeNode (nums[mid]);
        node->left = help(low,mid-1,nums);
        node->right = help(mid+1,high,nums);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* res = help(0,nums.size()-1,nums);
        return res;
    }
};