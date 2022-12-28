class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int res = 0;
        int low = 0;
        int high = people.size()-1;
        while(low<high)
        {
            int sum = people[low] + people[high];
            if(sum <= limit)
            {
                res++;
                low++;
                high--;
            }
            else if(sum > limit)
            {
                res++;
                high--;
            }
        }
        if(low==high)
        {
            res++;
        }
        return res;
    }
};