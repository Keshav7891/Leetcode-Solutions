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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL)
        {
            return NULL;
        }
        int len = 0;
        ListNode* curr = head;
        while(curr != NULL)
        {
            len++;
            curr = curr->next;
        }
        n = len - n;
        curr = head;
        ListNode* prev = NULL;
        while(n--)
        {
            prev = curr;
            curr = curr->next;
        }
        if(curr == head)  return head->next;
        prev->next = curr->next;
        return head;
    }
};