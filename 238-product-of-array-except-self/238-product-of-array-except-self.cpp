class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int>res;
        int p=1;
        for(int i=0;i<nums.size();i++)  //computing left impact
        {
            p=p*nums[i];
            res.push_back(p);
        }
        p=1;
        for(int i=nums.size()-1;i>=1;i--)
        {
            res[i]=res[i-1]*p;  //left impact * right impact
            p=p*nums[i];        //updating right impact
        }
        res[0]=p;
        return res;
    }
};