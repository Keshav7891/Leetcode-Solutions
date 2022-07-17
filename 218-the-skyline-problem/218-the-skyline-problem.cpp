class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int>pq;
    
    pq.insert(0);
    
    vector<vector<int>>ans;
    vector<pair<int,int>>pairs;
    
    for(auto it:buildings)
    {
        int sp=it[0],ep=it[1],h=it[2];
        pairs.push_back({sp,-h});
        pairs.push_back({ep,h});
    }
    
    sort(pairs.begin(),pairs.end());
    
    int cht=0;
    
    for(auto it:pairs)
    {
        int x=it.first;
        int ht=it.second;
        
        if(ht<0)
            pq.insert(-ht);
        
        else
            pq.erase(pq.find(ht));
        
        if(cht!=*pq.rbegin())
        {
            vector<int>temp;
            temp.push_back(x);
            temp.push_back(*pq.rbegin());
            
            ans.push_back(temp);
            
            cht=*pq.rbegin();
        }
    }
    
    return ans;
}
};