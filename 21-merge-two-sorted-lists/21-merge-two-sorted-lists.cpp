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
        
        ListNode *curr1 = list1;
        ListNode *curr2 = list2;
        ListNode *res = new ListNode(0);
        ListNode* fres = res;
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val==list2->val)
            {
                res->next = list1;
                res=res->next;
                list1=list1->next;
            }
            else if(list1->val<list2->val)
            {
                res->next = list1;
                list1=list1->next;
                res=res->next;
            }
            else if(list1->val>list2->val)
            {
                res->next = list2;
                list2=list2->next;
                res=res->next;
            }
        }
        while(list1!=NULL)
        {
            res->next = list1;
            res=res->next;
            list1=list1->next;
        }
        while(list2!=NULL)
        {
            res->next = list2;
            list2=list2->next;
            res=res->next;
        }
        return fres->next;
    }
};