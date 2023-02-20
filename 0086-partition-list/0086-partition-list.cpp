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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smaller = new ListNode(-1);
        ListNode* greater = new ListNode(-1);
        ListNode* curr1 = smaller;
        ListNode* curr2 = greater;
        ListNode* curr = head;
        
        while(curr != NULL)
        {
            int val = curr->val;
            if(val < x)
            {
                smaller->next = curr;
                smaller = smaller->next;
                curr = curr->next;
            }
            else 
            {
                greater->next = curr;
                greater = greater->next;
                curr = curr->next;
            }
        }
        greater->next = NULL;
        smaller->next = curr2->next;
        return curr1->next;
    }
};