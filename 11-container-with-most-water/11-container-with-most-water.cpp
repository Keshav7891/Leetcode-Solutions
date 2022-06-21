class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int low = 0;
        int high = height.size()-1;
        int area;
        int res = INT_MIN;
        while(low<high)
        {
            int len = high - low;
            int h = min(height[low],height[high]);
            
            int area = h*len;
            res = max(res,area);
            
            if(height[high]>height[low])
            {
                low++;
            }
            else 
            {
                high--;
            }
        }
        return res;
        
    }
};