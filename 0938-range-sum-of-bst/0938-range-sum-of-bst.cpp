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
    void help(TreeNode* root , int low , int high , int &sum)
    {
        if(root == NULL)
        {
            return ;
        }
        int curr = root->val;
        if(low <= curr && curr <= high)
        {
            sum = sum + curr;
        }
        help(root->left,low,high,sum);
        help(root->right,low,high,sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        help(root,low,high,sum);
        return sum;
    }
};