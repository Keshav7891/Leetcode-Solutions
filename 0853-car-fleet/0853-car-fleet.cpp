class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>nums;
        for(int i=0;i<speed.size();i++){
            nums.push_back({position[i],speed[i]});
        }
        int res = 0;
        bool first = false;
        double curr = -1;
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=0;i--){
            double index = nums[i].first * 1.0;
            double velocity = nums[i].second * 1.0;
            double time = (target*1.0 - index) / velocity;
            //cout<<time<<" ";
            if(first == false){
                first = true;
                curr = time;
                res++;
            }else{
                if(time > curr){
                    curr = max(curr,time);
                    res++;
                }
            }
        }
        return res;
    }
};