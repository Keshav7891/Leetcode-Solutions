class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins)
    {
        sort(costs.begin(),costs.end());
        int sum=0,count=0;
        for(int i=0;i<costs.size();i++)
        {
            if(sum<coins)
            {
                sum=sum+costs[i];
                count++;
            }
            if(sum==coins)
            {
                return count;
            }
            if(sum>coins)
            {
                return count-1;
            }
        }
        return count;
    }
};