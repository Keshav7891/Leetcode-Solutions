class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        for(int i=0;i<nums.size()-2;i++)
        {
            int target = 0 - nums[i];
            int low = i+1;
            int high = nums.size()-1;
            //cout<<i<<" "<<low<<" "<<high<<endl;
            if(( i==0) || (i>0 && nums[i]!=nums[i-1]))
            {
                while(low < high)
                {
                    int a = nums[i];
                    int b = nums[low];
                    int c = nums[high];
                    //cout<<target<<" "<<b+c<<endl;
                    if(b+c == target)
                    {
                        res.push_back({a,b,c});
                        while(low <= nums.size()-1 && nums[low] == b)
                        {
                            low++;
                        }
                        while(high >= 0 && nums[high] == c)
                        {
                            high--;
                        }
                    }
                    else if(b+c < target)
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