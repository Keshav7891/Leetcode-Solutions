class Solution {
public:
    int canCompleteCircuit(vector<int>& petrol, vector<int>& distance)
    {
        int defi = 0;
        int balance = 0;
        int start = 0;
        for(int i=0;i<petrol.size();i++)
        {
            balance = balance + (petrol[i]-distance[i]);
            if(balance<0)
            {
                defi = defi + balance;
                start = i+1;
                balance = 0;   
            }
        }
        if(defi+balance >= 0 )
        {
            return start;
        }
        else
        {
            return -1;
        }
    }
};