/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
        if(low > high)  return NULL;
        int mid = (low+high)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = help(low,mid-1,nums);
        root->right = help(mid+1,high,nums);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>nums;
        while(head != NULL)
        {
            nums.push_back(head->val);
            head = head -> next;
        }
        TreeNode* res = help(0,nums.size()-1,nums);
        return res;
    }
};