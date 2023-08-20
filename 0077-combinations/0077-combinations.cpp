class Solution {
public:
    // _ _
    vector<vector<int>>res;
    void help(int n , int index , int k , vector<int>&path){
        if(k==0){
            res.push_back(path);
            return;
        }
        // if(index > n){
        //     return;
        // }
        
        for(int i=index;i<=n;i++){
            path.push_back(i);
            //cout<<i<<" ";
            help(n,i+1,k-1,path);
            path.pop_back();
        }
        
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>path;
        help(n,1,k,path);
        return res;
    }
};