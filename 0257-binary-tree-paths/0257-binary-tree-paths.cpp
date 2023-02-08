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
    void help(TreeNode* root , string path , vector<string>&res)
    {
        if(root == NULL)
        {
            return ;
        }
        if(root->left == NULL && root->right == NULL)
        {
            path = path + to_string(root->val);
            res.push_back(path);
        }
        string curr = to_string(root->val);
        help(root->left,path+curr+"->",res);
        help(root->right,path+curr+"->",res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = "";
        vector<string>res;
        help(root,path,res);
        return res;
    }
};