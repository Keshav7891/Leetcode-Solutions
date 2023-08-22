class Solution {
public:
    int totalFruit(vector<int>& nums) {
        unordered_map<int,int>m;
        int res = 0;
        int j = 0;
        for(int i=0;i<nums.size();i++){
            int curr = nums[i];
            m[curr]++;
            while(j<i && m.size() > 2){
                int temp = nums[j];
                m[temp]--;
                j++;
                if(m[temp] == 0){
                    m.erase(temp);
                }
            }
            //cout<<i<<" "<<j<<endl;
            
            res = max(res,i-j+1);   
            
        }
        return res;
    }
};