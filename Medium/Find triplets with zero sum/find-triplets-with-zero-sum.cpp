//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
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
                
                if(sum == 0){
                    return true;
                }else if(sum > 0){
                    high--;
                    while(low<high && arr[high] == arr[high+1]) high--;
                }else if(sum < 0){
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
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends