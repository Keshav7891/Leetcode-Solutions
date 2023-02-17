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
    int k=0;
    unordered_map<int,int>m;
    TreeNode* help(int low , int high , vector<int>&preorder , vector<int>&inorder)
    {
        if(low > high)  return NULL;
        
        int curr = preorder[k];
        int index = m[curr];
        k++;
        TreeNode* root = new TreeNode(curr);
        root->left = help(low,index-1,preorder,inorder);
        root->right = help(index+1,high,preorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
        {
            m[inorder[i]] = i;
        }
        return help(0,inorder.size()-1,preorder,inorder);
    }
};