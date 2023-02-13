/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        q.push(root);
        if(root == NULL)    return NULL;
        while(q.empty()==false)
        {
            int size = q.size();
            Node* prev = NULL;
            for(int i=0;i<size;i++)
            {
                auto curr = q.front();
                q.pop();
                
                //cout<<curr->val<<" "<<i<<" ";
                if(i==0)
                {
                    prev = curr;
                }
                else if(i==size-1)
                {
                    prev->next = curr;
                    curr->next = NULL;
                }
                else
                {
                    prev->next = curr;
                    prev = curr;
                }
                
                if(curr->left != NULL)  q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
            }
            //cout<<endl;
        }
        
        return root;
    }
};