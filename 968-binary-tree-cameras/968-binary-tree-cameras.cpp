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
    int no_camera = 0;
    int not_needed = 1;
    int has_camera = 2;
    int res = 0;
    int insert_camera(TreeNode* root)
    {
        if(root==NULL)
        {
            return not_needed;
        }
        
        int left_node = insert_camera(root->left);
        int right_node = insert_camera(root->right);
        
        if(left_node == no_camera || right_node == no_camera)
        {
            res++;
            return has_camera;
        }
        else if(left_node == has_camera || right_node == has_camera)
        {
            return not_needed;
        }
        else if(left_node == not_needed || right_node == not_needed)
        {
            return no_camera;
        }
        else
        {
            return no_camera;
        }
    }
    int minCameraCover(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(root->left==NULL && root->right==NULL)
        {
            return 1;
        }
        int remaining_request = insert_camera(root);
        if(remaining_request==no_camera)
        {
            res++;
        }
        return res;
    }
};