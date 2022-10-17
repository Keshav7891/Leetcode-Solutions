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
    int sumEvenGrandparent(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int res = 0;
        while(q.empty()==false)
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                auto curr = q.front();
                q.pop();
                if(curr->val % 2 == 0)
                {
                    int ll = 0;
                    int lr = 0;
                    if(curr->left!=NULL && curr->left->left!=NULL)
                    {
                        ll = curr->left->left->val;
                    }
                    if(curr->left!=NULL && curr->left->right!=NULL)
                    {
                        lr = curr->left->right->val;
                    }
                    int rl = 0;
                    int rr = 0;
                    if(curr->right!=NULL && curr->right->left!=NULL)
                    {
                        rl = curr->right->left->val;
                    }
                    if(curr->right!=NULL && curr->right->right!=NULL)
                    {
                        rr = curr->right->right->val;
                    }
                    res = res + (ll + lr) + (rl + rr);
                }
                if(curr->left!=NULL)
                {
                    q.push(curr->left);
                }
                if(curr->right!=NULL)
                {
                    q.push(curr->right);
                }
            }
        }
        return res;
    }
};