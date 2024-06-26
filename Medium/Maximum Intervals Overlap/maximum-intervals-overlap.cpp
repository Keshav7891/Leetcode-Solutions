//{ Driver Code Starts
// Program to find maximum guest at any time in a party
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> findMaxGuests(int Entry[], int Exit[], int N)
    {
       // Your code goes here
       sort(Entry, Entry + N);
       sort(Exit, Exit + N);
       
       int t = -1, guests = 0, max_guests = 0, i = 0, j = 0;
       
       while (i < N && j < N) {
           if (Entry[i] <= Exit[j]) {
               guests++;
               if (max_guests < guests) {
                   max_guests = guests;
                   t = Entry[i];
               }
               i++;
           } else {
               guests--;
               j++;
           }
       }
       
       return {max_guests, t};
    }

};

//{ Driver Code Starts.

 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int entry[n],exit1[n];
        for(i=0;i<n;i++)
        cin>>entry[i];
        for(i=0;i<n;i++)
        cin>>exit1[i];
        Solution obj;

	    vector<int> p = obj.findMaxGuests(entry, exit1, n);
	    cout<<p[0]<<' '<<p[1];
	    cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends