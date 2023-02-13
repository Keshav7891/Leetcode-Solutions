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
    int dir(TreeNode* root,int dest,string &s){
        if(root==NULL){
            return 0;
        }
        if(root->val==dest){
            return 1;
        }
        s.push_back('L');
        if(dir(root->left,dest,s)) return 1;
        s.pop_back();
        s.push_back('R');
        if(dir(root->right,dest,s)) return 1;
        s.pop_back();
        return 0;
    }
    TreeNode* help1(TreeNode* root , int startValue , int destValue)
    {
        if(root == NULL)
        {
            return NULL;
        }
        if(root->val == startValue || root->val == destValue)
        {
            return root;
        }
        
        TreeNode* left = help1(root->left,startValue,destValue);
        TreeNode* right = help1(root->right,startValue,destValue);
        
        if(left != NULL && right != NULL)
        {
            return root;
        }
        else if(left == NULL && right != NULL)
        {
            return right;
        }
        else if(left != NULL && right == NULL)
        {
            return left;
        }
        else
        {
            return NULL;
        }
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = help1(root,startValue,destValue);
        string a="",b="";
        dir(LCA,startValue,a);
        dir(LCA,destValue,b);
        for(auto &it:a){
            it='U';
        }
        return a+b;
    }
};