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
        if(depth==0)
        {
            return root;
        }
        if(depth==1)
        {
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        queue<TreeNode*>q;
        q.push(root);
        int level = 1;
        while(q.empty()==false)
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                auto curr = q.front();
                q.pop();
                
                if(level == depth-1)
                {
                    TreeNode* currLeft = curr->left;
                    TreeNode* currRight = curr->right;
                    
                    TreeNode* tempLeft = new TreeNode(val);
                    TreeNode* tempRight = new TreeNode(val);
                    
                    curr->left = tempLeft;
                    tempLeft->left = currLeft;
                    
                    curr->right = tempRight;
                    tempRight->right = currRight;
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
            level++;
        }
        
        return root;
    }
};