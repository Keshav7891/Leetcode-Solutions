class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL || head->next==NULL || k==0)
        {
            return head;
        }
        ListNode *curr = head , *kth = head , *tail = NULL;
        int len = 1;
        while(curr->next!=NULL)
        {
            len++;
            curr=curr->next;
        }
        curr->next=head;
        int rotatelist = len - k%len ;
        while(rotatelist>0)
        {
            tail = kth;
            kth=kth->next;
            rotatelist--;
        }
        head=kth;
        tail->next=NULL;
        return head;
    }
};