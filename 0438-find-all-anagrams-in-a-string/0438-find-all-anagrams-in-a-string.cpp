class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        for(int i=0;i<p.size();i++){
            m1[p[i]]++;
            m2[s[i]]++;
        }
        vector<int>res;
        if(m1 == m2){
            res.push_back(0);
        }
        int k=0;
        for(int i=p.size();i<s.size();i++){
            m2[s[i]]++;
            m2[s[k]]--;
            if(m2[s[k]] == 0){
                m2.erase(s[k]);
            }
            k++;
            if(m1 == m2){
                //cout<<"Found"<<endl;
                res.push_back(i-p.size()+1);
            }
            // for(auto key : m2){
            //     cout<<key.first<<" "<<key.second<<endl;
            // }
            // cout<<endl;
        }
        return res;
    }
};