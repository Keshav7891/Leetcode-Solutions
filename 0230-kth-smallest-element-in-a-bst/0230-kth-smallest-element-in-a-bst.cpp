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
    int res = -1;
    void help(TreeNode* root,int &k)
    {
        if(root == NULL)
        {
            return ;
        }
        help(root->left,k);
        int curr = root->val;
        k--;
        if(k==0)    res = curr;
        help(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        help(root,k);
        return res;
    }
};