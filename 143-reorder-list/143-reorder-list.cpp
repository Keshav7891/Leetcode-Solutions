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
        
        while(curr!=NULL)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev;
    }
    void reorderList(ListNode* head)
    {
        ListNode* curr1 = head;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* curr2 = reverse(slow->next);
        slow->next = NULL;
        
        while(curr1!=NULL && curr2!=NULL)
        {
            ListNode* temp1 = curr1->next;
            ListNode* temp2 = curr2->next;
            
            curr1->next= curr2;
            curr2->next = temp1;
            
            curr1 = temp1;
            curr2 = temp2;
            
            
        }
        
        

    }
};