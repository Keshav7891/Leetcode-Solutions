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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<double>res;
        
        while(q.empty()==false)
        {
            int size = q.size();
            double sum = 0;
            for(int i=0;i<size;i++)
            {
                auto curr = q.front();
                q.pop();
                
                sum = sum + curr->val;
                
                if(curr->left!=NULL)
                {
                    q.push(curr->left);
                }
                if(curr->right!=NULL)
                {
                    q.push(curr->right);
                }
            }
            double avg = sum / size * 1.0;
            res.push_back(avg);
        }
        
        return res;
    }
};