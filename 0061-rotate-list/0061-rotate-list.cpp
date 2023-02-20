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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)    return NULL;
        int len = 0;
        ListNode* curr = head;
        while(curr != NULL)
        {
            len++;
            curr = curr->next;
        }
        k = k % len;
        if(k==0 || head->next==NULL)    return head;
        k = len - k;
        ListNode* curr2 = head;
        ListNode* res;
        ListNode* end = NULL;
        while(k--)
        {
            end = curr2;
            curr2 = curr2->next;
        }
        res = curr2;
        while(curr2->next != NULL)
        {
            curr2 = curr2->next;
        }
        curr2->next = head;
        end->next = NULL;
        return res;
    }
};