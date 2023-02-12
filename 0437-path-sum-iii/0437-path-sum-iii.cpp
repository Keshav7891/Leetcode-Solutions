class Solution {
public:
    void path(TreeNode* root,int &n,long long int targetSum) {
        // base case
        if(root == NULL) return;
        targetSum -= root->val;
        if(targetSum == 0){
            n++;
        }
        path(root->left,n,targetSum);
        path(root->right,n,targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        int n = 0;
        path(root,n,targetSum);
        return n + pathSum(root->left,targetSum) + pathSum(root->right,targetSum);        

    }
};