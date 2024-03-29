class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int j = matrix[0].size()-1;
        
        while(i<matrix.size() && j>=0)
        {
            int curr = matrix[i][j];
            if(curr == target)
            {
                return true;
            }
            else if(target > curr)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        
        return false;
    }
};