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
    unordered_map<int,int>m;
    void help(TreeNode* root)
    {
        if(root == NULL)
        {
            return ;
        }
        m[root->val]++;
        help(root->left);
        help(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        help(root);
        int mx = INT_MIN;
        vector<int>res;
        for(auto key : m)
        {
            int freq = key.second;
            if(freq > mx)
            {
                mx = freq;
            }
        }
        for(auto key : m)
        {
            int val = key.first;
            int freq = key.second;
            if(freq == mx)
            {
                res.push_back(val);
            }
        }
        return res;
    }
};