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
    ListNode* healp(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int carry = 0;
        while(curr1 != NULL || curr2 != NULL)
        {
            int a = 0;
            int b = 0;
            if(curr1 != NULL)
            {
                a = curr1->val;
                curr1 = curr1->next;
            }
            if(curr2 != NULL)
            {
                b = curr2->val;
                curr2 = curr2->next;
            }
            
            int sum = a + b + carry;
            carry= sum/10;
            
            ListNode* node = new ListNode(sum%10);
            curr->next = node;
            curr = curr->next;
        }
        
        if(carry != 0)
        {
            curr->next = new ListNode(carry);
        }
        
        return dummy->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* res = healp(l1,l2);
        res = reverse(res);
        return res;
    }
};