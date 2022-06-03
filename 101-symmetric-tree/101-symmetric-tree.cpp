class Solution {
public:
    bool help(TreeNode* left_sub_tree,TreeNode* right_sub_tree)
    {
        if(left_sub_tree==NULL && right_sub_tree==NULL)
        {
            return true;
        }
        if(left_sub_tree==NULL || right_sub_tree==NULL)
        {
            return false;
        }
        if(left_sub_tree->val!=right_sub_tree->val)
        {
            return false;
        }
        return help(left_sub_tree->left,right_sub_tree->right) && help(left_sub_tree->right,right_sub_tree->left);
    }
    bool isSymmetric(TreeNode* root)
    {
        if(root==NULL)
        {
            return true;
        }
        bool res = help(root->left,root->right);
        return res;
        
        
    }
};