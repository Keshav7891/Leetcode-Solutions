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
    int countNodes(TreeNode* root) {
        int count = 0;
        queue<TreeNode*>q;
        q.push(root);
        if(root == NULL)    return 0;
        while(q.empty()==false)
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                auto curr = q.front();
                q.pop();
                
                count++;
                
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
        return count;
    }
};