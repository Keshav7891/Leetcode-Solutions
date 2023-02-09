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
    int getMaxIndex(int low , int high , vector<int>&nums)
    {
        int maxe = INT_MIN;
        int index = -1;
        
        for(int i=low;i<=high;i++)
        {
            int curr = nums[i];
            if(curr > maxe)
            {
                index = i;
                maxe = curr;
            }
        }
        
        return index;
    }
    
    
    TreeNode* help(int low , int high , vector<int>&nums)
    {
        if(low > high)
        {
            return NULL;
        }
        
        int index = getMaxIndex(low,high,nums);
        TreeNode* root = new TreeNode(nums[index]);
        
        root->left = help(low , index-1 , nums);
        root->right = help(index+1 , high , nums);
        
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return help(0,nums.size()-1,nums);
    }
};