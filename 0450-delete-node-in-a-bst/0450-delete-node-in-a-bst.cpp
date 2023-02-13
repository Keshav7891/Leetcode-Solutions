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
    TreeNode* help(TreeNode *curr)
    {
        curr=curr->right;
        while(curr!=NULL && curr->left!=NULL)
        {
            curr=curr->left;
        }
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
        {
            return NULL;
        }
        else if(root->val > key)
        {
            root->left = deleteNode(root->left,key);
        }
        else if(root->val < key)
        {
            root->right = deleteNode(root->right,key);
        }
        else
        {
            if(root->left == NULL && root->right != NULL)
            {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->left != NULL && root->right == NULL)
            {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else if(root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            else
            {
                TreeNode* node = help(root);
                root->val = node->val;
                root->right = deleteNode(root->right,node->val);
            }
        }
        return root;
    }
};