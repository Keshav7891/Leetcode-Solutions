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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode *fast = head, *kth = NULL , *slow = head;
        k=k-1;
        while(k>0)
        {
            fast=fast->next;
            k--;
        }
        kth=fast;
        fast=fast->next;
        while(fast!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        swap(kth->val,slow->val);
        return head;
        
    }
};