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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>res;
        if(root == NULL)    return res;
        
        while(q.empty()==false)
        {
            int size = q.size();
            int maxe = INT_MIN;
            for(int i=0;i<size;i++)
            {
                auto curr = q.front();
                q.pop();
                
                maxe = max(maxe , curr->val);
                
                if(curr->left != NULL)  q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
            }
            res.push_back(maxe);
        }
        
        return res;
    }
};