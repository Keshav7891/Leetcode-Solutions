class Solution {
public:
    int getDecimalValue(ListNode* head) 
    {
        ListNode *temp=head;
        int i,c=0,res=0;
        while(temp!=NULL)
        {
            c++;
            temp=temp->next;
        }
        temp=head;
        for(i=c-1;i>=0;i--)
        {
            res=res + (temp->val * pow(2,i));
            temp=temp->next;
        }
        return res;
        
    }
};