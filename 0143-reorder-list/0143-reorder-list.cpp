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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr != NULL)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* head2 = reverse(slow->next);
        slow->next = NULL;
        
        ListNode* res = head;
        ListNode* curr1 = head;
        ListNode* curr2 = head2;
        
        while(curr2 != NULL)
        {
            ListNode* temp1 = curr1->next;
            ListNode* temp2 = curr2->next;
            
            curr1->next = curr2;
            curr2->next = temp1;
            
            curr1 = temp1;
            curr2 = temp2;
        }
    }         
};