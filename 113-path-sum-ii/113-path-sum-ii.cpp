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
    vector<vector<int>>res;
    bool help(TreeNode *root , int target , vector<int>path)
    {
        if(root==NULL)
        {
            return false;
        }
        
        target = target - root->val;
        path.push_back(root->val);
        
        if(target==0 && root->left==NULL && root->right==NULL)
        {
            res.push_back(path);
        }
        
        bool left = help(root->left,target,path);
        bool right = help(root->right,target,path);
        
        path.pop_back();
        return left or right;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        vector<int>path;
        bool check = help(root,targetSum,path);
        return res;
    }
};