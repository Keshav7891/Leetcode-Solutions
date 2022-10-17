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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>graph;
        unordered_map<int,int>check;
        for(auto key : descriptions)
        {
            int parentVal = key[0];
            int childVal = key[1];
            int dir = key[2];
            
            if(check.find(parentVal)==check.end())
            {
                check[parentVal] = 1;   
            }
            check[childVal] = 0;
            
            TreeNode* prnt = NULL;
            TreeNode* child = NULL;
            
            if(graph.find(parentVal)==graph.end())
            {
                prnt = new TreeNode(parentVal);
                graph[parentVal] = prnt;
            }
            else
            {
                prnt = graph[parentVal];
            }
            
            if(graph.find(childVal)==graph.end())
            {
                child = new TreeNode(childVal);
                graph[childVal] = child;
            }
            else
            {
                child = graph[childVal];
            }
            
            if(dir == 1)
            {
                //cout<<prnt->val<<" "<<child->val<<" left"<<endl;
                prnt->left = child;
            }
            else
            {
                //cout<<prnt->val<<" "<<child->val<<" right"<<endl;
                prnt->right = child;
            }
        }
        int resVal;
        for(auto key : check)
        {
            if(key.second!=0)
            {
                resVal = key.first;
                break;
            }
        }
        return graph[resVal];
    }
};