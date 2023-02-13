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
    void help(TreeNode* root , int target , vector<int>path)
    {
        if(root == NULL)
        {
            return;
        }
        
        if(root->left == NULL && root->right == NULL)
        {
            if(target - root->val == 0)
            {
                path.push_back(root->val);
                res.push_back(path);
            }
        }
        
        int curr = root->val;
        path.push_back(curr);
        help(root->left,target-curr,path);
        help(root->right,target-curr,path);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        help(root,targetSum,path);   
        return res;
    }
};