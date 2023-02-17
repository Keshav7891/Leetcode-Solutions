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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int>s;
        for(auto key : nums)
        {
            s.insert(key);
        }
        int components = 0;
        ListNode* curr = head;
        
        while(curr != NULL)
        {
            int val = curr->val;
            if(s.find(val)!=s.end())
            {
                while(curr->next!=NULL && s.find(val) != s.end())
                {
                    //cout<<curr->val<<" ";
                    curr = curr->next;
                    val = curr->val;
                }
                components++;
                curr = curr->next;
            }
            else
            {
                //cout<<curr->val<<" ";
                curr = curr->next;   
            }
        }
        
        return components;
    }
};