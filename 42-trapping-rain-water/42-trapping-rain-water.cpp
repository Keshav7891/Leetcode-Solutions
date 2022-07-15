class Solution {
public:
    int trap(vector<int>& height) 
    {
        int res=0,n=height.size(),i;
        vector<int> lmax(n);
        vector<int> rmax(n);
        lmax[0]=height[0];
        rmax[n-1]=height[n-1];
        for(i =1;i<n;i++)
        {
            lmax[i]=max(height[i],lmax[i-1]);
        }
        for(i=n-2;i>=0;i--)
        {
            rmax[i]=max(height[i],rmax[i+1]);
        }
        for(i=1;i<n-1;i++)
        {
            res=res+(min(lmax[i],rmax[i])-height[i]);
        }
        return res;
    }
};