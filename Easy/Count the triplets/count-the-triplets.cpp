//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
    int countTriplet(int nums[], int n)
	{
	    
	   sort(nums,nums+n);
	   reverse(nums,nums+n);
	    
	   int res = 0;
	   for(int i=0;i<n;i++){
	       int low = i+1;
	       int high = n-1;
	       while(low<high){
	           //cout<<nums[i]<<" "<<nums[low]<<" "<<nums[high]<<endl;
	           if(nums[low] + nums[high] == nums[i]){
	               res++;
	               low++;
	               high--;
	           }else if(nums[low] + nums[high] > nums[i]){
	               //cout<<"Moving right"<<endl;
	               low++;
	           }else{
	               //cout<<"Moving left"<<endl;
	               high--;
	           }
	       }
	       //cout<<endl;
	   }
	   return res;
	}
};

//{ Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}
// } Driver Code Ends