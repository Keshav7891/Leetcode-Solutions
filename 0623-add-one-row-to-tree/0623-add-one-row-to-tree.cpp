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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*>q;
        q.push(root);
        int level = 1;
        if(depth == 1)
        {
            TreeNode* curr = new TreeNode (val);
            curr->left = root;
            return curr;
        }
        while(q.empty() == false)
        {
            level++;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                auto curr = q.front();
                q.pop();
                
                if(level == depth)
                {
                    TreeNode* cl = curr->left;
                    TreeNode* cr = curr->right;
                    curr->left = new TreeNode(val);
                    curr->right = new TreeNode(val);
                    curr->left->left = cl;
                    curr->right->right = cr;
                }
                
                if(curr->left != NULL)
                {
                    q.push(curr->left);
                }
                if(curr->right != NULL)
                {
                    q.push(curr->right);
                }
            }
        }
        return root;
    }
};