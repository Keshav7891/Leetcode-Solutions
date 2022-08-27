class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *ans = new ListNode (0);
        ListNode *curr = ans;
        ListNode *p = l1 , *q = l2;
        int carry = 0,sum = 0,x,y;
        while(p!=NULL || q!=NULL)
        {
            if(p!=NULL)
            {
                x=p->val;
                p=p->next;
            }
            else
            {
                x=0;
            }
            if(q!=NULL)
            {
                y=q->val;
                q=q->next;
            }
            else
            {
                y=0;
            }
            sum = carry + x + y;
            carry= sum/10;
            curr->next = new ListNode (sum%10);
            curr=curr->next;
        }
        if(carry>0)
        {
           curr->next = new ListNode (carry); 
        }
        return ans->next;
        
    }
};