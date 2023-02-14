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
class CBTInserter {
public:
    TreeNode* root = NULL;
    CBTInserter(TreeNode* node) {
        root = node;
    }
    
    int insert(int val) {
        queue<TreeNode*>q;
        q.push(root);
        int prnt;
        bool inserted = false;
        while(q.empty()==false)
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                auto curr = q.front();
                q.pop();
                
                if(curr->left != NULL)  
                {
                    q.push(curr->left);
                }
                else
                {
                    if(inserted == false)
                    {
                        inserted = true;
                        prnt = curr->val;
                        curr->left = new TreeNode(val);
                    }
                }
                
                if(curr->right != NULL)
                {
                    q.push(curr->right);
                }
                else
                {
                    if(inserted == false)
                    {
                        inserted = true;
                        prnt = curr->val;
                        curr->right = new TreeNode(val);
                    }
                }
            }
        }
        return prnt;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */