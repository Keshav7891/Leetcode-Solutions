class Solution {
public:
    int help(int ele ,  vector< pair< pair<int,int >,int>>&nums){
        int low = 0;
        int high = nums.size()-1;
        int index = -1;
        while(low<=high){
            int mid = (low + high)/2;
            if(nums[mid].first.first >= ele){
                index = nums[mid].second;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return index;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector< pair< pair<int,int >,int>>nums;
        // vector<int>res;
        // for(int i=0;i<intervals.size();i++){
        //     int foundIndex = -1;
        //     int foundEle = INT_MAX;
        //     for(int j=0;j<intervals.size();j++){
        //         if(i!=j && intervals[j][0] >= intervals[i][1] && intervals[j][0] < foundEle){
        //             foundEle = intervals[j][0];
        //             foundIndex = j;
        //         }
        //     }
        //     res.push_back(foundIndex);
        // }
        for (int i = 0; i < intervals.size(); i++) {
            nums.push_back({{intervals[i][0], intervals[i][1]}, i});
        }
        vector<int>res;
        sort(nums.begin(),nums.end());
        for(auto key : intervals){
            int ele = key[1];
            int index = help(ele,nums);
            res.push_back(index);
        }
        return res;
    }
};