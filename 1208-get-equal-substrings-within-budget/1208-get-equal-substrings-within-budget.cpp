class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int res = 0;
        int j = 0;
        int currCost = 0;
        for(int i=0;i<s.size();i++){
            int a = s[i] - 'a';
            int b = t[i] - 'a';
            int cost1 = abs(a-b);
            
            //cout<<cost1<<" "<<currCost<<endl;
            
            currCost = currCost + cost1;
            
            while(currCost > maxCost){
                int c = s[j] - 'a';
                int d = t[j] - 'a';
                int cost2 = abs(c-d);
                currCost = currCost - cost2;
                //cout<<"Reduce "<<cost2<<" "<<currCost<<endl;
                j++;
            }
            
            res = max(res,i-j+1);
        }
        return res;
    }
};