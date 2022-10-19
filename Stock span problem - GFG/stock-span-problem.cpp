//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        stack<int>s;
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            if(s.empty()==true)
            {
                res.push_back(-1);
            }
            else if(s.empty()==false && price[ s.top() ] > price[i] )
            {
                res.push_back(s.top());
            }
            else if(s.empty()==false && price[ s.top() ] <= price[i])
            {
                while(s.empty()==false && price[ s.top() ] <= price[i])
                {
                    s.pop();
                }
                if(s.empty()==true)
                {
                    res.push_back(-1);
                }
                else
                {
                    res.push_back(s.top());
                }
            }
            s.push(i);
        }
        for(int i=0;i<res.size();i++)
        {
            res[i] = i - res[i];
        }
        return res;
       // Your code here
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends