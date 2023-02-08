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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>q;
        q.push(root);
        int parent_x , parent_y;
        int level_x,level_y;
        int level = 0;
        while(q.empty() == false)
        {
            int size = q.size();
            level++;
            for(int i=0;i<size;i++)
            {
                auto curr = q.front();
                q.pop();
                
                if(curr->left != NULL)
                {
                    if(curr->left->val == x)
                    {
                        level_x = level;
                        parent_x = curr->val;
                    }
                    else if(curr->left->val == y)
                    {
                        level_y = level;
                        parent_y = curr->val;
                    }
                    q.push(curr->left);
                }
                
                if(curr->right != NULL)
                {
                    if(curr->right->val == x)
                    {
                        level_x = level;
                        parent_x = curr->val;
                    }
                    else if(curr->right->val == y)
                    {
                        level_y = level;
                        parent_y = curr->val;
                    }
                    q.push(curr->right);
                }
            }
        }
        cout<<level_x<<" "<<level_y<<endl;
        if(level_x == level_y)
        {
            if(parent_x != parent_y)
            {
                return true;
            }
        }
        
        return false;
    }
};