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
    ListNode* oddEvenList(ListNode* head)
    {
        if(head==NULL) return head;
        ListNode *odd_head = head;
        ListNode *odd_element = head;
        
        ListNode *even_head = head->next;
        ListNode *even_element = head->next;
        
        while(even_element!=NULL && even_element->next!=NULL)
        {
            odd_element->next = odd_element->next->next;
            even_element->next = even_element->next->next;
            
            odd_element = odd_element->next;
            even_element = even_element->next;
        }
        
        odd_element->next = even_head;
        return odd_head;
    }
};