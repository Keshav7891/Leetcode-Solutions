class Solution {
public:
    TreeNode *first=NULL,*second=NULL;
    TreeNode *adjacent=NULL;
    TreeNode *prev_node=new TreeNode(INT_MIN); 
    void help(TreeNode *root)
    {
        if(root==NULL)
        {
            return;
        }
        help(root->left);
        if(prev_node!=NULL && (prev_node->val>root->val))
        {
            if(first==NULL)
            {
                first=prev_node;
                adjacent=root;
            }
            else
            {
                second=root;
            }
        }
        prev_node=root;
        help(root->right);
    }
    void recoverTree(TreeNode* root) 
    {
        help(root);
        if(first!=NULL && second!=NULL && adjacent!=NULL)
        {
            swap(first->val,second->val);
        }
        else if(first!=NULL && second==NULL &&adjacent!=NULL)
        {
            swap(first->val,adjacent->val);
        }
        
    }
};