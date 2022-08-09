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
    int sumNumbers(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        queue<pair<TreeNode*,int>>q;
        q.push({root,root->val});
        int res = 0;
        while(q.empty()==false)
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                auto curr = q.front();
                q.pop();

                auto node = curr.first;
                int sum = curr.second;

                if(node->left!=NULL)
                {
                    q.push({node->left,sum*10 + node->left->val});
                }
                if(node->right!=NULL)
                {
                    q.push({node->right,sum*10 + node->right->val});
                }
                if(node->left==NULL && node->right==NULL)
                {
                    res=res+sum;
                }
            }
        }
        return res;

    }
};