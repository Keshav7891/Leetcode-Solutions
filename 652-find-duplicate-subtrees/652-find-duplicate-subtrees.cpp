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
    vector<TreeNode*>res;
    unordered_map<string,int>m;
    string help(TreeNode* root)
    {
        if(root==NULL)
        {
            return "";
        }

        string curr = to_string(root->val);
        string left = 'L' + help(root->left);
        string right = 'R' + help(root->right);

        string key = left + curr + right;
        if(m[key]==1)
        {
            res.push_back(root);
        }
        m[key]++;
        return key;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        
        help(root);
        return res;
    }
};