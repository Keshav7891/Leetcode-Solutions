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
    int pre_index=0;
    TreeNode* help(vector<int>& preorder, vector<int>& inorder , int index_start , int index_end)
    {
        if(index_start>index_end)
        {
            return NULL;
        }
        
        TreeNode *root = new TreeNode(preorder[pre_index]);
        pre_index++;
        
        int in_index;
        
        for(int i=index_start;i<=index_end;i++)
        {
            if(inorder[i]==root->val)
            {
                in_index=i;
                break;
            }
        }
        
        root->left=help(preorder,inorder,index_start,in_index-1);
        root->right=help(preorder,inorder,in_index+1,index_end);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        TreeNode *root = help(preorder,inorder,0,preorder.size()-1);
        return root;
        
    }
};