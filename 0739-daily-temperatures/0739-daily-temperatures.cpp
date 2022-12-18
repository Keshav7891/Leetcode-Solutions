class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums)
    {
        vector<int>res;
        stack<int>s;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(s.empty()==true)
            {
                res.push_back(i);
            }
            else if(s.empty()==false && nums[s.top()]>nums[i])
            {
                res.push_back(s.top());
            }
            else if(s.empty()==false && nums[s.top()]<=nums[i])
            {
                while(s.empty()==false && nums[s.top()]<=nums[i])
                {
                    s.pop();
                }
                if(s.empty()==true)
                {
                    res.push_back(i);
                }
                else
                {
                    res.push_back(s.top());
                }
            }
            s.push(i);
        }
        reverse(res.begin(),res.end());
        for(int i=0;i<nums.size();i++)
        {
            res[i]=res[i]-i;
        }
        return res;
        
    }
};