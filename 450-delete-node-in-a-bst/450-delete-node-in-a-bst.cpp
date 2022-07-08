class Solution {
public:
    TreeNode* getsuccesor(TreeNode *curr)
    {
        curr=curr->right;
        while(curr!=NULL && curr->left!=NULL)
        {
            curr=curr->left;
        }
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->val>key)
        {
            root->left=deleteNode(root->left,key);
        }
        else if (root->val<key)
        {
            root->right=deleteNode(root->right,key);
        }
        else
        {
            if(root->left==NULL)
            {
                TreeNode *temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL)
            {
                TreeNode *temp=root->left;
                delete root;
                return temp;
            }
            else
            {
                TreeNode *succesor = getsuccesor(root);
                root->val=succesor->val;
                root->right=deleteNode(root->right,succesor->val);
            }
        }
        return root;
            
        
    }
};