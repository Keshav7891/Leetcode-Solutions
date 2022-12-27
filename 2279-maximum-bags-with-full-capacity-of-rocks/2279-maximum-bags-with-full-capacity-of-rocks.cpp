class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        for(int i=0;i<capacity.size();i++)
        {
            capacity[i]=capacity[i]-rocks[i];
        }
        sort(capacity.begin(),capacity.end());
        int count = 0;
        for(int i=0;i<capacity.size();i++)
        {
            if(capacity[i]==0)
            {
                count++;
                continue;
            }
            else
            {
                int val = capacity[i];
                if(additionalRocks>=val)
                {
                    count++;
                    additionalRocks=additionalRocks-val;
                }
                else
                {
                    break;
                }
            }
        }
        return count;
    }
};