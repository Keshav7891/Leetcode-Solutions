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
class Solution {
public:
    ListNode* partition(ListNode* head, int x)
    {
        ListNode* small = new ListNode(-1);
        ListNode* small_head = small;
        ListNode* bigg = new ListNode(-1);
        ListNode* bigg_head = bigg;
        
        ListNode* curr = head;
        while(curr!=NULL)
        {
            if(curr->val<x)
            {
                small->next = curr;
                small = small->next;
            }
            else if(curr->val>=x)
            {
                bigg->next = curr;
                bigg = bigg->next;
            }
            
            curr=curr->next;
        }
        
        bigg->next = NULL;
        bigg_head = bigg_head -> next;
        small->next = bigg_head;
        
        return small_head->next;
        
    }
};