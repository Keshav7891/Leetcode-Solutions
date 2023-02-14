class Solution {
public:
   int ans = 0;
    void rec(int no,TreeNode* root)
    {
        if(!root)
            return;
        no = no*2 + root->val;
        if(root->left==NULL&&root->right==NULL)
        {
            ans+=no;
            return;
        }
        rec(no,root->left);
        rec(no,root->right);
    }

    int sumRootToLeaf(TreeNode* root) {
          ans = 0;
        rec(0,root);
        return ans;
    }
};