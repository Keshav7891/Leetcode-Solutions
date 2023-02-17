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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)  return {};
        int count = 0;
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>res;
        while(q.empty()==false)
        {
            count++;
            int size = q.size();
            vector<int>path;
            for(int i=0;i<size;i++)
            {
                auto curr = q.front();
                q.pop();
                
                path.push_back(curr->val);
                
                if(curr->left != NULL)
                {
                    q.push(curr->left);
                }
                if(curr->right != NULL)
                {
                    q.push(curr->right);
                }
            }
            if(count%2 == 0)
            {
                reverse(path.begin(),path.end());
            }
            res.push_back(path);
        }
        return res;
    }
};