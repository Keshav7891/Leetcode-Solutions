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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            int prev = level % 2 == 0 ? INT_MIN : INT_MAX;
            for (int i = 0; i < n; ++i) {
                TreeNode* t = q.front();
                q.pop();
                if (level % 2 == 0) {
                    if (t->val % 2 == 0 || t->val <= prev) return false;
                } else {
                    if (t->val % 2 == 1 || t->val >= prev) return false;
                }
                prev = t->val;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            ++level;
        }
        return true;
    }
};