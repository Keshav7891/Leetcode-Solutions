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
    void help(TreeNode* root,vector<string>& res, string curr)
    {
       if(root==NULL)
       {
           return;
       }
        if(root->left==NULL && root->right==NULL)
        {
            curr=curr+to_string(root->val);
            res.push_back(curr);
            return;
        }
        curr=curr+to_string(root->val);
        curr=curr+"->";
        help(root->left,res,curr);
        help(root->right,res,curr);
    }
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string>res;
        help(root,res,"");
        return res;
    }
};