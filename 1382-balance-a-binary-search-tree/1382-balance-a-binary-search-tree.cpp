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
        
        int index = (low+high)/2;
        TreeNode* root = new TreeNode(nums[index]);
        
        root->left = help(low , index-1 , nums);
        root->right = help(index+1 , high , nums);
        
        return root;
    }
    void help1(TreeNode* root , vector<int>&nums)
    {
        if(root == NULL)
        {
            return ;
        }
        help1(root->left,nums);
        nums.push_back(root->val);
        help1(root->right,nums);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>nums;
        help1(root,nums);
        TreeNode* res = help(0,nums.size()-1,nums);
        return res;
    }
};