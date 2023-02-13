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
    string res = "";
    void help(TreeNode* root , string path)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->left == NULL && root->right == NULL)
        {
            char curr = (char) root->val + 97;
            path = path + curr;
            reverse(path.begin(),path.end());
            if(res == "")
            {
                res = path;
            }
            else if(path < res)
            {
                res = path;
            }
        }
        char curr = (char) root->val + 97;
        help(root->left,path + curr);
        help(root->right,path + curr);
    }
    string smallestFromLeaf(TreeNode* root) {
        help(root,"");
        return res;
    }
};