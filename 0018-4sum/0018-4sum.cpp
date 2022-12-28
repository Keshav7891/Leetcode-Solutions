class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        set<vector<int>>s;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int a = nums[i];
                int b = nums[j];
                long long int sub = a+b;
                long long int rem = target - sub;
                int low = j+1;
                int high = nums.size()-1;
                while(low<high)
                {
                    int c = nums[low];
                    int d = nums[high];
                    long long int sum = c+d;
                    if(sum == rem)
                    {
                        s.insert({a,b,c,d});
                        low++;
                        high--;
                    }
                    else if(sum<rem)
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
        for(auto key : s)
        {
            res.push_back(key);
        }
        return res;
    }
};