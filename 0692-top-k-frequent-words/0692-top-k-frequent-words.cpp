class Solution {
public:
    
    
    static bool cmp(pair<string,int> a, pair<string,int> b)
    {
        if(a.second>b.second || (a.second==b.second && a.first<b.first))
            return true;
        return false;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        
        for(auto key : words)
            m[key]++;
        
        vector<pair<string,int>> nums;
        for(auto key : m)
            nums.push_back({key.first,key.second});
        
        sort(nums.begin(),nums.end(),cmp);
        
        vector<string> res;
        for(int i=0; i<k; i++)
        {
            res.push_back(nums[i].first);
        }
        
        return res;
    }
};