class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        
        int val1 = nums[0];
        int count1 = 1;
        int val2 = nums[0];
        int count2 = 0;
        
        for(int i=1;i<nums.size();i++)
        {
            int curr = nums[i];
            
            if(curr==val1)   //repeated value
            {
                count1++;
            }
            else if(curr==val2)    //repeated value
            {
                count2++;
            }
            else                    //pairing
            {
                if(count1 == 0)         //if all paired
                {
                    val1 = curr;
                    count1 = 1;
                }
                else if(count2 == 0)    //if all paired
                {
                    val2 = curr;
                    count2 = 1;
                }
                else                    //pairing
                {
                    count1--;
                    count2--;
                }
            }
        }
        
        //confirming frequency
        int freq1 = 0; 
        int freq2 = 0;
        
        for(auto key : nums)
        {
            if(key == val1)
            {
                freq1++;
            }
            else if(key == val2)
            {
                freq2++;
            }
        }
        
        vector<int>res;
        if(freq1>nums.size()/3) res.push_back(val1);
        if(freq2>nums.size()/3 && val1!=val2) res.push_back(val2);
        
        return res;
    }
};