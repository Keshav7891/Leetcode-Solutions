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
    int res = 0;
    bool isPalindrome(unordered_map<int,int>m)
    {
        int c=0;
        for(auto key : m)
        {
            if(key.second%2!=0)
            {
                c++;
            }
            if(c>1)
            {
                return false;
            }
        }
        return true;
    }
    void help(TreeNode* root, unordered_map<int,int>&m)
    {
        if(root==NULL)
        {
            return ;
        }
        m[root->val]++;
        if(root->left==NULL && root->right==NULL)
        {
            if(isPalindrome(m)==true)
            {
                res++;
            }
        }
        else
        {
            help(root->left,m);
            help(root->right,m);
        }
        m[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root)
    {
        unordered_map<int,int>m;
        help(root,m);
        return res;
    }
};