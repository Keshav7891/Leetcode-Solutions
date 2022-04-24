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
    void reverse(ListNode *head , ListNode *tail)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        while(prev!=tail)
        {
            ListNode *nex = curr->next;
            curr->next = prev;
            prev=curr;
            curr=nex;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode (-1);
        dummy->next = head;
        ListNode *beforestart = dummy;
        ListNode *end = head;
        int i=0;
        while(end!=NULL)
        {
            i++;
            if(i%k==0)
            {
                ListNode *start = beforestart->next;
                ListNode *temp = end->next;
                reverse(start,end);
                beforestart->next=end;
                start->next = temp;
                beforestart=start;
                end = temp;
            }
            else
            {
                end = end->next;
            }
        }
        return dummy->next;
    }
};