class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto key : nums){
            m[key]++;
        }
        int j = 0;
        int res = 0;
        int unique = m.size();
        m.clear();
        
        for(int i=0;i<nums.size();i++){
            int curr = nums[i];
            m[curr]++;
            
            while(m.size()==unique){
                res = res + nums.size() - i;
                int temp = nums[j];
                m[temp]--;
                j++;
                if(m[temp]==0){
                    m.erase(temp);
                }
            }
        }
        
        return res;
    }
};