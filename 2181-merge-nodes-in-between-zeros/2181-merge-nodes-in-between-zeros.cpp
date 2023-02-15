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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* first_zero = NULL;
        ListNode* second_zero = NULL;
        int res = 0;
        ListNode* curr = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;
        
        while(curr != NULL)
        {
            if(curr->val == 0 && first_zero == NULL)
            {
                first_zero = curr;
            }
            else if(curr->val != 0 && first_zero != NULL)
            {
                res = res + curr->val;
            }
            else if(curr->val == 0 && first_zero != NULL && second_zero == NULL)
            {
                dummy->next = new ListNode(res);
                dummy = dummy->next;
                
                res = 0;
                first_zero = curr;
                second_zero = NULL;
            }
            curr = curr->next;
        }
        
        return ans->next;
    }
};