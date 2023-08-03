class Solution {
public:
    int maximumSwap(int num) {
        string nums = to_string(num);
        map<char,int , greater<int>>m;
        for(int i=0;i<nums.size();i++){
            char curr = nums[i];
            m[curr] = i;
        }
        
        for(int i=0;i<nums.size();i++){
            char curr = nums[i];
            for(auto key : m){
                //cout<<key.first<<" "<<curr<<endl;
                if(key.first > curr && key.second > i){
                    swap(nums[i],nums[key.second]);
                    return stoi(nums);
                }
            }
            //cout<<endl;
        }
        
        return num;
    }
};