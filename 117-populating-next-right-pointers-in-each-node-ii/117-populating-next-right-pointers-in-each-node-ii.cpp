
class Solution {
public:
    Node* connect(Node* root)
    {
        if(root==NULL)
        {
            return root;
        }
        queue<Node*>q;
        q.push(root);
        while(q.empty()==false)
        {
            int count=q.size();
            while(count>0)
            {
                auto curr = q.front();
                q.pop();
                count--;
                auto next_element=q.front();
                if(count>0)
                {
                    curr->next=next_element;
                }
                else if (count==0)
                {
                    curr->next=NULL;
                }
                if(curr->left!=NULL)
                {
                    q.push(curr->left);
                }
                if(curr->right!=NULL)
                {
                    q.push(curr->right);
                }
            }
        }
        return root;
        
    }
};