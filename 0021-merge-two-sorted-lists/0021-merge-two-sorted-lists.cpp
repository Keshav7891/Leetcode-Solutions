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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* k = new ListNode(-1);
        ListNode* res = k;
        
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        
        while(curr1 != NULL && curr2 != NULL)
        {
            int val1 = curr1->val;
            int val2 = curr2->val;
            
            if(val1 < val2)
            {
                k->next = curr1;
                curr1 = curr1->next;
                k = k->next;
            }
            else
            {
                k->next = curr2;
                curr2 = curr2->next;
                k = k->next;
            }
        }
        
        while(curr1 != NULL)
        {
            k->next = curr1;
            curr1 = curr1->next;
            k = k->next;
        }
        
        while(curr2 != NULL)
        {
            k->next = curr2;
            curr2 = curr2->next;
            k = k->next;
        }
        
        return res->next;
        
    }
};