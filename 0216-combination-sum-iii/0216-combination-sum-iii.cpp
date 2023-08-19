class Solution {
public:
    vector<vector<int>>res;
    void help(int index , int target , vector<int>&path,int k){
        if(target==0 && path.size()==k){
            res.push_back(path);
            return;
        }
        for(int i=index;i<=9;i++){
            if(target-i >= 0){
                path.push_back(i);
                help(i+1,target-i,path,k);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<int>path;
        help(1,target,path,k);
        return res;
    }
};