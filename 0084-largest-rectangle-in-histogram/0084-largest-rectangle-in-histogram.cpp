class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        vector<int>nsl;
        vector<int>nsr;
        int n = nums.size();
        stack<int>s;
        
        for(int i=0;i<n;i++)
        {
            int curr = nums[i];
            int index = i;
            
            if(s.empty()==true)
            {
                nsl.push_back(-1);
            }
            else if(s.empty()==false && nums[s.top()] < curr)
            {
                nsl.push_back(s.top());
            }
            else if(s.empty()==false && nums[s.top()] >= curr)
            {
                while(s.empty()==false && nums[s.top()] >= curr)
                {
                    s.pop();
                }
                if(s.empty()==false)
                {
                    nsl.push_back(s.top());
                }
                else
                {
                    nsl.push_back(-1);
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
                nsr.push_back(-1);
            }
            else if(s.empty()==false && nums[s.top()] < curr)
            {
                nsr.push_back(s.top());
            }
            else if(s.empty()==false && nums[s.top()] >= curr)
            {
                while(s.empty()==false && nums[s.top()] >= curr)
                {
                    s.pop();
                }
                if(s.empty()==false)
                {
                    nsr.push_back(s.top());
                }
                else
                {
                    nsr.push_back(-1);
                }
            }
            s.push(index);
        }
        reverse(nsr.begin(),nsr.end());
        int res = INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(nsr[i]==-1)
            {
                nsr[i] = n;
            }
            int area = nums[i] * (nsr[i] - nsl[i] - 1);
            //cout<<nums[i]<<" "<<nsl[i]<<" "<<nsr[i]<<" "<<area<<endl;
            res = max(res,area);
        
        }
        return res;
    }
};