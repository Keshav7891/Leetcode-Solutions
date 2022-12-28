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
    bool res = false;
    void help(TreeNode* root,int target,unordered_set<int>&s)
    {
        if(root == NULL)
        {
            return ;
        }
        int curr = root->val;
        if(s.find(target-curr)!=s.end())
        {
            res = true;
        }
        else
        {
            s.insert(curr);
        }
        help(root->left,target,s);
        help(root->right,target,s);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>s;
        help(root,k,s);
        return res;
    }
};