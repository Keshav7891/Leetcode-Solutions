//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    void merge(long long arr[], long long low, long long mid, long long high, long long N, long long &res){
        long long i = low;
        long long j = mid+1;
        
        vector<long long>temp;
        
        while(i<=mid && j<=high){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }else{
                res += (mid - i + 1);
                temp.push_back(arr[j]);
                j++;
            }
        }
        
        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        
        while(j<=high){
            temp.push_back(arr[j]);
            j++;
        }
        
        for(long long i=low;i<=high;i++){
            arr[i] = temp[i-low];
        }
    }
    
    void mergeSort(long long arr[] , long long low, long long high, long long N, long long &res){
        if(low == high){
            return;
        }
        
        long long mid = (low + high)/2;
        
        mergeSort(arr,low,mid,N,res);
        mergeSort(arr,mid+1,high,N,res);
        
        merge(arr, low, mid, high, N, res);
    }
    
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long res = 0;
        long long low = 0;
        long long high = N - 1;
        mergeSort(arr, low, high, N, res);
        return res;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends