class Solution {
public:
        int solve_at_most(vector<int> nums, int k){
    int n = nums.size();
    int res = 0;
    int i=0,j=0;
    unordered_map<int,int> mp;
    
    while(j < n){
        mp[nums[j]]++;
        
        while(mp.size() > k){
            mp[nums[i]]--;
            if(mp[nums[i]] == 0)
                mp.erase(nums[i]);
            i++;
        }
        res += j-i+1;
        j++;
    }
    return res;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    int res = solve_at_most(nums,k) - solve_at_most(nums,k-1);
    return res;
}
};