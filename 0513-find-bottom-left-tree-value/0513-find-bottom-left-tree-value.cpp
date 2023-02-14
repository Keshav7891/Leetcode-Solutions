 class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {

        if(!root)
        return -1;

        queue<TreeNode*> q;
        q.push(root);

        int ans = -1;
        while(!q.empty())
        {
            int c = q.size();
            
            for(int i=1; i<=c; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(i==1)
                ans = node->val;

                if(node->left)
                q.push(node->left);

                if(node->right)
                q.push(node->right);

            }
            
        }

        return ans;
    }
};