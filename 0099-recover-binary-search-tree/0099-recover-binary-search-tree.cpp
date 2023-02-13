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
    TreeNode* v1 = NULL;
    TreeNode* v2 = NULL;
    TreeNode* v3 = NULL;
    TreeNode* prev = NULL;
    int count = 0;
    void help(TreeNode* root)
    {
        if(root == NULL)
        {
            return ;
        }
        help(root->left);
        if(prev == NULL) 
        {
            prev = root;
        }
        else
        {
            //cout<<root->val<<" "<<prev->val<<endl;
            if(root->val < prev->val && count == 0)
            {
                v1 = prev;
                v2 = root;
                count++;
            }
            else if(root->val < prev->val)
            {
                v3 = root;
            }
            prev = root;
        }
        help(root->right);
    }
    void recoverTree(TreeNode* root) {
        help(root);
        //1 3 2 4

        if(v1 != NULL && v2 != NULL && v3 == NULL)
        {
            swap(v1->val,v2->val);
        }
        else if(v1 != NULL && v2 != NULL && v3 != NULL)
        {
            swap(v1->val,v3->val);
        }
    }
};