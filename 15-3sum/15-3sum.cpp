class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(( i==0) || (i>0 && nums[i]!=nums[i-1]))
            {
                int target = 0 - nums[i];
                int low = i+1;
                int high = nums.size()-1;
                while(low<high)
                {
                    if(nums[low] + nums[high] == target)
                    {
                        int a = nums[i];
                        int b = nums[low];
                        int c = nums[high];
                        res.push_back({a,b,c});
                        while(low<high && b==nums[low])
                        {
                            low++;
                        }
                        while(low<high && c==nums[high])
                        {
                            high--;
                        }
                    }
                    else if(nums[low] + nums[high] < target)
                    {
                        low++;
                    }
                    else
                    {
                        high--;
                    }
                }
            }
        }
        return res;
    }
};