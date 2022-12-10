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
    const unsigned int mod = 1000000007;
    int help(TreeNode* root , long long int total , long long int &res)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        long long int left = help(root->left,total,res);
        long long int right = help(root->right,total,res);
        
        long long int subtree = root->val + left + right;
        long long int val = (subtree * (total - subtree));
        res = max(res , val);
        
        return subtree;
        
    }
    void help1(TreeNode* root , long long int &sum)
    {
        if(root == NULL)
        {
            return ;
        }
        sum = sum + root->val;
        help1(root->left,sum);
        help1(root->right,sum);
    }
    int maxProduct(TreeNode* root) {
        long long int sum = 0;
        help1(root,sum);
        long long int res = 0;
        help(root , sum , res);
        return res % mod;
        
    }
};