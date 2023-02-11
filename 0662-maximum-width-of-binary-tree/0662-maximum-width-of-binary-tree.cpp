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
    int widthOfBinaryTree(TreeNode* root) 
    {
        long res=0;
        if(root==NULL)
        {
            return res;
        }
        queue<pair<TreeNode*,long>>q;
        q.push({root,0});
        while(q.empty()==false)
        {
            int count=q.size();
            long first,last;
            long minn=q.front().second;
            for(int i=0;i<count;i++)
            {
                long curr_id=q.front().second-minn;
                auto temp=q.front().first;
                q.pop();
                if(i==0)
                {
                    first=curr_id;
                }
                if(i==count-1)
                {
                    last=curr_id;
                }
                if(temp->left!=NULL)
                {
                    q.push({temp->left,2*curr_id+1});
                }
                 if(temp->right!=NULL)
                {
                    q.push({temp->right,2*curr_id+2});
                }
            }
            res=max(res,last-first+1);
        }
        return res;
    }
};