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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr = list1;
        ListNode* prev = NULL;
        while(a--)
        {
            prev = curr;
            curr = curr->next;
        }
        curr = list1;
        while(b--)
        {
            curr = curr->next;
        }
        //cout<<prev->val<<" "<<curr->val<<endl;
        ListNode* curr2 = list2;
        while(curr2->next != NULL)
        {
            curr2 = curr2->next;
        }
        prev->next = list2;
        curr2->next = curr->next;
        return list1;
    }
};