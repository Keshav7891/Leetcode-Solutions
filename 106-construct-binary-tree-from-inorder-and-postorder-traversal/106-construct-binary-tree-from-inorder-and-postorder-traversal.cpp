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
    unordered_map<int,int>m;
    TreeNode* help(vector<int>& inorder , vector<int>& postorder , int &index , int start_index , int end_index)
    {
        if(start_index>end_index)
        {
            return NULL;
        }
        
        TreeNode *root=new TreeNode (postorder[index]);
        index--;
        int in_index;
        
        for(int i=start_index;i<=end_index;i++)
        {
            if(inorder[i]==root->val)
            {
                in_index=i;
                break;
            }
        }
        
        root->right = help(inorder,postorder,index,in_index+1,end_index);
        root->left = help(inorder,postorder,index,start_index,in_index-1);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int n=inorder.size();
        for(int i=0;i<n;i++)
        {
            m[inorder[i]]=i;
        }
        int index=n-1;
        TreeNode *root = help(inorder,postorder,index,0,n-1);
        return root;
    }
};