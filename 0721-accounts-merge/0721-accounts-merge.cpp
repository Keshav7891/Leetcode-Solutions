class DSU
{
    public : 
        vector<int>parent;
        vector<int>size;
        DSU(int n)
        {
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++)
            {
                parent[i] = i;
            }
        }
        
        int findParent(int node)
        {
            if(node == parent[node])
            {
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }
        
        void unionBySize(int u , int v)
        {
            int pu = findParent(u);
            int pv = findParent(v);
            
            if(pu == pv)
            {
                return ;
            }
            
            if(size[pu] < size[pv])
            {
                parent[pu] = pv;
                size[pv] = size[pv] + size[pu];
            }
            else
            {
                parent[pv] = pu;
                size[pu] = size[pu] + size[pv];
            }
        }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
       int n = accounts.size();
        DSU ds(n);
        unordered_map<string, int> mp;
        for(int i = 0; i < n; ++i){
            for(int j = 1; j < accounts[i].size(); ++j){
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }
                else{
                    ds.unionBySize(i, mp[mail]);
                }
            }
        }
        
        vector<string> mergedMail[n];
        for(auto it : mp){
            string mail = it.first;
            int node = ds.findParent(it.second);
            mergedMail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        for(int i = 0; i < n; ++i){
            if(mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};