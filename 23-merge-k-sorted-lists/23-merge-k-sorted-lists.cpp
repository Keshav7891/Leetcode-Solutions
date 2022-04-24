/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class cmp 
{
    public:
    bool operator() (ListNode *a , ListNode *b)
    {
        return a->val>b->val;
    }
};
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp>q;
        for(auto key : lists)
        {
            if(key!=NULL)
            {
                q.push(key);
            }
        }
        ListNode *res = new ListNode (-1);
        ListNode *tail = res;
        while(q.empty()==false)
        {
            auto top = q.top();
            tail->next = top;
            tail=tail->next;
            q.pop();
            if(top->next!=NULL)
            {
                q.push(top->next);
            }
        }
        return res->next;
    }
};