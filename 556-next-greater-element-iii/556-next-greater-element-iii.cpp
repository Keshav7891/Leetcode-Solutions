class Solution {
public:
    int nextGreaterElement(int n)
    {
        string s = to_string(n);
        int i=0;
        //Finding The position of greater element which have a lesser element before it while traversing backward
        for(i=s.size()-1;i>0;i--)
        {
            if(s[i]>s[i-1])
                break;  
        }
        //If No Element Found
        if(i==0)
        {
            return -1;
        }
        //If we find a bigger element then we surely have a smaller element before it hence element = s[i-1]
        int element = s[i-1];
        int small = i;
        //we now i+1 element is smaller than i and i-1 elemnt is also smaller than i hence we compare both and check again s[j] ie s[i+1] is less than s[i] ie s[small] and store small as j if both condition satisfy
        for(int j=i+1;j<s.size();j++)
        {
            if((s[j]>element)&&(s[j]<=s[small]))
            {
                small=j;
            }
        }
        //Swap those twho numbvers
        swap(s[small],s[i-1]);
        // before swaping - 1597      after swaping - 1795      after sort - 1759 hence we obtain min maximum number that is greater than n
        sort(s.begin()+i,s.end());
        //converting bact to integer
        long res = stol(s);   
        //Chechking if its out of range
        if((res<n)||(res>INT_MAX))
        {
            return -1;
        }
        else
        {
            return res;
        }
    }
};