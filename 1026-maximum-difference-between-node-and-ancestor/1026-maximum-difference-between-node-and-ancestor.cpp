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
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        queue< pair<TreeNode*,pair<int,int>> >q;
        q.push({root,{INT_MAX,INT_MIN}});
        while(q.empty() == false)
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                auto curr = q.front();
                auto node = curr.first;
                int minParent = curr.second.first;
                int maxParent = curr.second.second;
                q.pop();
                
                if(minParent != INT_MAX && maxParent != INT_MIN)
                {
                    int val1 = abs(minParent - node->val);
                    int val2 = abs(maxParent - node->val);
                    res = max({val1,val2,res});
                }
                
                if(node->left != NULL)
                {
                    minParent = min(minParent,node->val);
                    maxParent = max(maxParent,node->val);
                    q.push({node->left,{minParent,maxParent}});
                }
                
                if(node->right != NULL)
                {
                    minParent = min(minParent,node->val);
                    maxParent = max(maxParent,node->val);
                    q.push({node->right,{minParent,maxParent}});
                }
            }
        }
        return res;
        
    }
};