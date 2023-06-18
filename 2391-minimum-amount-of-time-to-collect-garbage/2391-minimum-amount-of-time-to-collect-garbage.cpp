class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        for(int i=1;i<travel.size();i++){
            travel[i] = travel[i] + travel[i-1];
        }
        
        travel.insert(travel.begin(), 0);
        
        int g = 0;
        int p = 0;
        int m = 0;
        int res = 0;
        
        for(int i=0;i<garbage.size();i++){
            
            int garbageCount = 0;
            int paperCount = 0;
            int metalCount = 0;
            
            for(auto key : garbage[i]){
                if(key == 'G')  garbageCount++;
                if(key == 'P')  paperCount++;
                if(key == 'M')  metalCount++;
            }
            
            
            if(garbageCount != 0){
                int distance = travel[i] - travel[g];
                res = res + distance + garbageCount;
                g = i;
            }
            
            if(paperCount != 0){
                int distance = travel[i] - travel[p];
                res = res + distance + paperCount;
                p = i;
            }
            
            if(metalCount != 0){
                int distance = travel[i] - travel[m];
                res = res + distance + metalCount;
                m = i;
            }
            
        }
        
        return res;
        
        
    }
};