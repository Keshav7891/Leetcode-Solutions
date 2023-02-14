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
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr != NULL)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = reverse(slow->next);
        slow->next = NULL;
        ListNode* curr1 = head;
        ListNode* curr2 = head2;
        
        while(curr2!=NULL)
        {
            if(curr1->val != curr2->val)
            {
                return false;
            }
            curr1=curr1->next;
            curr2=curr2->next;
        }
        
        return true;
        
    }
};