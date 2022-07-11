class Solution {
public:
    bool checkPath(ListNode* head, TreeNode* root) {
        // if the list has ended
        if(!head)
            return true;
        // if the list hasnt ended but tree has
        if(!root)
            return false;

        return head->val == root->val && (checkPath(head->next, root->left) ||
                                         checkPath(head->next, root->right));
    }

    // TC: O(M * min(M, N)), M: size of linked list, N: No. of nodes in tree
    bool isSubPath(ListNode* head, TreeNode* root) {
        queue<TreeNode*> q;
        q.emplace(root);

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

            // check if the current node match the list head
            if(curr->val == head->val && checkPath(head, curr))
                return true;

            if(curr->left)
                q.emplace(curr->left);
            if(curr->right)
                q.emplace(curr->right);
        }

        return false;
    }
};