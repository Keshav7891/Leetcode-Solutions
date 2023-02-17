/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
int k;
unordered_map<int,int>m;
TreeNode* help(int low , int high , vector<int>& inorder, vector<int>& postorder)
{
if(low > high)  return NULL;
int curr = postorder[k];
k--;
int index = m[curr];
TreeNode* root = new TreeNode(curr);
root->left = help(low,index-1,inorder,postorder);
root->right = help(index+1,high,inorder,postorder);
return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
for(int i=0;i<inorder.size();i++)
{
m[inorder[i]] = i;
}
k = postorder.size()-1;
return help(0,k,inorder,postorder);
}
};