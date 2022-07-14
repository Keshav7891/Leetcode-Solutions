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
    int find_largest(int start , int end , vector<int>nums)
    {
        int index = -1;
        int maxe = INT_MIN;
        for(int i=start;i<=end;i++)
        {
            if(nums[i]>maxe)
            {
                maxe = nums[i];
                index = i;
            }
        }
        return index;
    }
    TreeNode *help(int start , int end , vector<int>nums)
    {
        if(start>end)
        {
            return NULL;
        }
        
        int index = find_largest(start,end,nums);
        TreeNode *node = new TreeNode(nums[index]);
        
        node->left = help(start,index-1,nums);
        node->right = help(index+1,end,nums);
        
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        int start = 0;
        int end = nums.size()-1;
        TreeNode *res = help(start,end,nums);
        return res;
    }
};