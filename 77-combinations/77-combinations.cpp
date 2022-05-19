class Solution {
public:
    vector<vector<int>>res;
    void combinations(int index , int total_box , int selected , vector<int>&path , vector<int>&nums , int k)
    {
        if(index==total_box)
        {
            if(selected == k)
            {
                res.push_back(path);
            }
            return;
        }
        path.push_back(nums[index]);
        combinations(index+1,total_box,selected+1,path,nums,k);
        path.pop_back();
        combinations(index+1,total_box,selected,path,nums,k);
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int>nums;
        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);
        }
        vector<int>path;
        combinations(0,n,0,path,nums,k);
        return res;
        
    }
};