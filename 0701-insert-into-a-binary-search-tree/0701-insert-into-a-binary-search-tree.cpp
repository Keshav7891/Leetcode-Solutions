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
    TreeNode* insertIntoBST(TreeNode* root, int x) {
        if(root == NULL)
        {
            TreeNode* node = new TreeNode(x);
            return node;
        }
        TreeNode* curr = root;
        TreeNode* prev;
        while(curr != NULL)
        {
            if(curr->val > x)
            {
                prev = curr;
                curr = curr->left;
            }
            else
            {
                prev = curr;
                curr = curr->right;
            }
        }
        if(prev->val > x)
        {
            prev->left = new TreeNode(x);
        }
        else
        {
            prev->right = new TreeNode(x);
        }
        
        return root;
    }
};