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
    ListNode* help(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr!=NULL)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *curr1 = head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = help(slow->next);
        int res = 0;
        ListNode* curr2 = slow->next;
        while(curr2!=NULL)
        {
            int sum = curr1->val + curr2->val;
            res = max(res,sum);
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return res;
    }
};