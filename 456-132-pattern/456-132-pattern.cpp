class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {
        if(nums.size()<3)
        {
            return false;
        }
        int min_arr[nums.size()];
        min_arr[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            min_arr[i]=min(min_arr[i-1],nums[i]);
        }
        stack<int>s;
        for(int j=nums.size()-1;j>=0;j--)
        {
            while(s.empty()==false && s.top()<nums[j])
            {
                if(s.top()>min_arr[j])
                {
                    return true;
                }
                s.pop();
            }
            s.push(nums[j]);
        }
        return false;
    }
};