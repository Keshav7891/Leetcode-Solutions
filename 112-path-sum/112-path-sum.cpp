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
    bool help(TreeNode* root, int sum)
    {
        if(root == NULL)
        {
            return false;
        }
        
        sum = sum - root->val;
        
        if(sum==0 && root->left==NULL && root->right==NULL)
        {
            return true;
        }
        
        bool left = help(root->left,sum);
        bool right = help(root->right,sum);
        
        return left||right;
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool res = help(root,targetSum);
        return res;
    }
};