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
    /*
    00  01  02  03  04
    10  11  12  13  14
    20  21  22  23  24
    */
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
            vector<vector<int>>nums(m,vector<int>(n,-1));
            ListNode* curr = head;
            int top=0,left=0,bottom=m-1,right=n-1,i;
            while(top<=bottom && left<=right)
            {
                for(i=left;i<=right;i++)
                {
                    if(curr!=NULL)
                    {
                        nums[top][i] = curr->val;
                        curr = curr->next;   
                    }
                    else
                    {
                        nums[top][i] = -1;
                    }
                }
                top++;
                for(i=top;i<=bottom;i++)
                {
                    if(curr!=NULL)
                    {
                        nums[i][right] = curr->val;
                        curr = curr->next;   
                    }
                    else
                    {
                        nums[i][right] = -1;
                    }
                }
                right--;
                if(top<=bottom)
                {
                    for(i=right;i>=left;i--)
                    {
                        if(curr!=NULL)
                        {
                            nums[bottom][i] = curr->val;
                            curr = curr->next;   
                        }
                        else
                        {
                            nums[bottom][i] = -1;
                        }
                    }
                    bottom--;
                }
                if(left<=right)
                {
                    for(i=bottom;i>=top;i--)
                    {
                        if(curr!=NULL)
                        {
                            nums[i][left] = curr->val;
                            curr = curr->next;   
                        }
                        else
                        {
                            nums[i][left] = -1;
                        }
                    }
                    left++;
                }
            }
        return nums;
        
    }
};