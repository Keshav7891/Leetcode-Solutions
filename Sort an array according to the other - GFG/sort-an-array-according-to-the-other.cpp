//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
//User function template in C++


class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> nums1, int N, vector<int> nums2, int M) 
    {
        map<int,int>m;
        for(auto key : nums1)
        {
            m[key]++;
        }
        vector<int>res;
        for(auto key : nums2)
        {
            while(m[key]>0)
            {
                res.push_back(key);
                m[key]--;
            }
            m.erase(key);
        }
        
        for(auto key : m)
        {
            int curr = key.first;
            while(m[curr]>0)
            {
                res.push_back(curr);
                m[curr]--;
            }
            m.erase(curr);
        }
        
        
        return res;
        
        
    } 
};

//{ Driver Code Starts.

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	}
	return 0; 
} 

// } Driver Code Ends