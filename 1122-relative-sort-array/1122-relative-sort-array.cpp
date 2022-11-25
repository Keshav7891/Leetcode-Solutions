class Solution {
public:
    vector<int> relativeSortArray(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>m;
        for(auto key : nums1)
        {
            m[key]++;
        }
        vector<int>res;
        for(auto key : nums2)
        {
            while(m[key]>0)
            {
                res.push_back(key);
                m[key]--;
            }
            m.erase(key);
        }
        
        for(auto key : m)
        {
            int curr = key.first;
            while(m[curr]>0)
            {
                res.push_back(curr);
                m[curr]--;
            }
            m.erase(curr);
        }
        
        
        return res;
        
    }
};