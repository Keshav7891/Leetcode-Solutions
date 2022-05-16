class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& nums, int m, int n) 
    {
        if(m*n!=nums.size())
        {
            return {};
        }
        int k=0;
        vector<vector<int>>matrix(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                matrix[i][j]=nums[k];
                k++;
            }
        }
        return matrix;
    }
};