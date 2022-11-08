class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
         vector<int>ngl;
        vector<int>ngr;
        int n = nums.size();
        stack<int>s;
        
        for(int i=0;i<n;i++)
        {
            int curr = nums[i];
            int index = i;
            
            if(s.empty()==true)
            {
                ngl.push_back(-1);
            }
            else if(s.empty()==false && nums[s.top()] < curr)
            {
                ngl.push_back(s.top());
            }
            else if(s.empty()==false && nums[s.top()] >= curr)
            {
                while(s.empty()==false && nums[s.top()] >= curr)
                {
                    s.pop();
                }
                if(s.empty()==false)
                {
                    ngl.push_back(s.top());
                }
                else
                {
                    ngl.push_back(-1);
                }
            }
            s.push(index);
        }
        
        s=stack<int>();
        
        for(int i=n-1;i>=0;i--)
        {
            int curr = nums[i];
            int index = i;
            
            if(s.empty()==true)
            {
                ngr.push_back(-1);
            }
            else if(s.empty()==false && nums[s.top()] < curr)
            {
                ngr.push_back(s.top());
            }
            else if(s.empty()==false && nums[s.top()] >= curr)
            {
                while(s.empty()==false && nums[s.top()] >= curr)
                {
                    s.pop();
                }
                if(s.empty()==false)
                {
                    ngr.push_back(s.top());
                }
                else
                {
                    ngr.push_back(-1);
                }
            }
            s.push(index);
        }
        reverse(ngr.begin(),ngr.end());
        int res = INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(ngr[i]==-1)
            {
                ngr[i] = n;
            }
            int area = nums[i] * (ngr[i] - ngl[i] - 1);
            //cout<<nums[i]<<" "<<ngl[i]<<" "<<ngr[i]<<" "<<area<<endl;
            res = max(res,area);
        
        }
        return res;
    }
};