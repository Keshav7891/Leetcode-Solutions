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
    pair<int,int> help(TreeNode* root)
    {
        if(root == NULL)
        {
            return {0,0};
        }
        
        pair<int,int> left_rob = help(root->left);
        pair<int,int> right_rob = help(root->right);
        
        int with_rob = left_rob.second + root->val + right_rob.second;
        int without_rob = max(left_rob.first,left_rob.second) + max(right_rob.first,right_rob.second);
        
        return {with_rob,without_rob};
    }
    int rob(TreeNode* root) {
        pair<int,int> res = help(root);
        int rob = res.first;
        int without_rob = res.second;
        return max(rob,without_rob);
    }
};