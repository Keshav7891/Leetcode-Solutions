//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    // 2 8 5 4
    // 2 4 5 8
    
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }

        int swaps = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != temp[i]) {
                int correctLocation = m[temp[i]];
                swap(nums[i], nums[correctLocation]); 
                m[nums[i]] = i; 
                m[nums[correctLocation]] = correctLocation; 
                swaps++; 
            }
        }

        return swaps;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends