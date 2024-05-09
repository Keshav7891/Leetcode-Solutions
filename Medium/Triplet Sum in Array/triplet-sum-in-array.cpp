//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int X)
    {
        sort(arr,arr+n);
        for(int i=0;i<n;i++){
            if(i > 0 && arr[i] == arr[i-1]){
                continue;
            }
            int low = i+1;
            int high = n-1;
            
            while(low < high){
                int sum = arr[i] + arr[low] + arr[high];
                
                if(sum == X){
                    return true;
                }else if(sum > X){
                    high--;
                    while(low<high && arr[high] == arr[high+1]) high--;
                }else if(sum < X){
                    low++;
                    while(low<high && arr[low] == arr[low-1]) low++;
                }
            }
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends