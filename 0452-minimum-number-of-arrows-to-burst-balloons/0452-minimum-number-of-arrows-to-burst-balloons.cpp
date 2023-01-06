bool cmp(vector<int>& a, vector<int>& b)
{
    return a[1] < b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int res = 1;
        for(auto key : points)
        {
            cout<<key[0]<<" "<<key[1]<<endl;
        }
        int end = points[0][1];
        for(int i=1;i<points.size();i++)
        {
            if(end>=points[i][0])
            {
                continue;
            }
            else
            {
                res++;
                end = points[i][1];
            }
        }
        return res;
    }
};