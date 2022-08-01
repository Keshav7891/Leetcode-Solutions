/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* copy , Node* node , unordered_map<int,Node*>&visited)
    {
        visited[copy->val] = copy;
        
        for(auto nbr : node->neighbors)
        {
            if(visited[nbr->val]==NULL)
            {
                Node* newNode = new Node(nbr->val);
                (copy->neighbors).push_back(newNode);
                dfs(newNode,nbr,visited);
            }
            else
            {
                (copy->neighbors).push_back(visited[nbr->val]);
            }
        }
    }
    Node* cloneGraph(Node* node)
    {
        if(node==NULL)
        {
            return NULL;
        }
        
        unordered_map<int,Node*>visited;
        Node* copy = new Node (node->val);
        dfs(copy,node,visited);
        return copy;
    }
};