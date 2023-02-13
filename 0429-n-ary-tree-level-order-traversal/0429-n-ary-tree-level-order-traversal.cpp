/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
         if(root == NULL)   return {};
        vector<vector<int>>res;
        queue<Node*>q;
        q.push(root);
        while(q.empty() == false)
        {
            vector<int>path;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                auto curr = q.front();
                q.pop();
                path.push_back(curr->val);
                for(auto key : curr->children)
                {
                    if(key != NULL)
                    {
                        q.push(key);
                    }
                }
            }
            res.push_back(path);
        }
        return res;
    }
};