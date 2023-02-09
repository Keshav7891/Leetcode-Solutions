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
    bool help(long low , long high , TreeNode* root)
    {
        if(root == NULL)
        {
            return true;
        }
        //cout<<root->val<<endl;
        int curr = root->val;
        if(low >= root->val || root->val >= high)
        {
            return false;
        }
        //cout<<low<<" "<<root->val<<" "<<high<<endl;
        bool left = help(low,root->val,root->left);
        bool right = help(root->val,high,root->right);
        
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        return help(LONG_MIN ,LONG_MAX ,root);
    }
};