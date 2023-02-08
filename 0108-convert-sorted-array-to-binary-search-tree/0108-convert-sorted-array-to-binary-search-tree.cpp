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
        if(low > high)
        {
            return NULL;
        }
        
        int mid = (low + high)/2;
        TreeNode* curr = new TreeNode (nums[mid]);
        
        curr->left = help(low,mid-1,nums);
        curr->right = help(mid+1,high,nums);
        
        return curr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        return help(low,high,nums);
    }
};