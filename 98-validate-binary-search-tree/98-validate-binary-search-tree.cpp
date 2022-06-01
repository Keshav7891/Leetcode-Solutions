class Solution {
public:
	bool help(TreeNode* root, long start, long end)
    {
		if(root == NULL)
        {
			return true;
		}   
		if(start < root->val && root->val < end) 
        {
			return help(root->left, start, root->val) && help(root->right, root->val, end);
		}    
        else
        {
              return false;
        }
	}
	bool isValidBST(TreeNode* root)
    {
		return help(root, LONG_MIN, LONG_MAX);
	} 
};