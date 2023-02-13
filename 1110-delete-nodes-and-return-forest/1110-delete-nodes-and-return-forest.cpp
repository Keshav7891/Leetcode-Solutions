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
    TreeNode* help(TreeNode* &root , unordered_set<int>&s , vector<TreeNode*>&res)
    {
        if(root == NULL)
        {
            return NULL;
        }
        
        int curr = root->val;
        if(s.find(curr)!=s.end())
        {
            TreeNode* l = help(root->left,s,res);
            TreeNode* r = help(root->right,s,res);
            if(l != NULL)
            {
                res.push_back(l);
            }
            if(r != NULL)
            {
                res.push_back(r);
            }
            delete root;
            return NULL;
        }
        
        root->left = help(root->left,s,res);
        root->right = help(root->right,s,res);
        
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>res;
        unordered_set<int>s;
        for(auto key : to_delete)
        {
            s.insert(key);
        }
        root = help(root,s,res);
        if(root != NULL)
        {
            res.push_back(root);
        }
        return res;
    }
};