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
    TreeNode* LCA(TreeNode* root1 , TreeNode* root2 , TreeNode* root)
    {
        if(root == NULL)
        {
            return NULL;
        }
        
        if(root->val == root1->val || root->val == root2->val)
        {
            return root;
        }
        
        TreeNode* left = LCA(root1,root2,root->left);
        TreeNode* right = LCA(root1,root2,root->right);
        
        if(left == NULL && right == NULL)
        {
            return NULL;
        }
        else if(left != NULL && right == NULL)
        {
            return left;
        }
        else if(left == NULL && right != NULL)
        {
            return right;
        }
        else
        {
            return root;
        }
    }
    
    TreeNode* help(vector<TreeNode*>&nodes , TreeNode* root)
    {
        if(nodes.size()==1)
        {
            return nodes[0];
        }
        
        TreeNode* res = nodes[0];
        for(int i=1;i<nodes.size();i++)
        {
            res = LCA(res,nodes[i],root);
        }
        
        return res;
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        
        vector<TreeNode*>nodes;
        
        while(q.empty()==false)
        {
            int size = q.size();
            if(nodes.size()>0)
            {
                nodes.clear();
            }
            for(int i=0;i<size;i++)
            {
                auto curr = q.front();
                q.pop();
                
                nodes.push_back(curr);
                
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
        
        TreeNode* res = help(nodes,root);
        
        return res;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return lcaDeepestLeaves(root);
    }
};