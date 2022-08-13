class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& nums) 
    {
        int r=nums.size(),c=nums[0].size();
        vector<int> res;
        int top=0,left=0,bottom=r-1,right=c-1,i;
            while(top<=bottom && left<=right)
            {
                for(i=left;i<=right;i++)
                {
                    res.push_back(nums[top][i]);
                }
                top++;
                for(i=top;i<=bottom;i++)
                {
                    res.push_back(nums[i][right]);
                }
                right--;
                if(top<=bottom)
                {
                    for(i=right;i>=left;i--)
                    {
                        res.push_back(nums[bottom][i]);
                    }
                    bottom--;
                }
                if(left<=right)
                {
                    for(i=bottom;i>=top;i--)
                    {
                        res.push_back(nums[i][left]);
                    }
                    left++;
                }
            }
        return res;
        
    }
};