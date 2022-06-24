class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int n=intervals.size(); //Calculating the size of intervals arrray
        sort(intervals.begin(),intervals.end()); // sorting array to make it simpler (increasing order of start cordinate)
        vector<vector<int>> result; //making result array to store maximized/overlapped co-ordinates
        result.push_back(intervals[0]);//for beginning adding first element
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<=result[result.size()-1][1])//check if ending of cordinate is bigger than beginning of next cordinate so they can be overlapped
            {
                result[result.size()-1][1] = max(result[result.size()-1][1],intervals[i][1]);//store the minimum beginning and maximum ending to get final overlapped co-ordinates
            }
            else
            {
                result.push_back(intervals[i]); // pushback the next co-ordinates if the previous one cannot be overlapped
            }
        }
        return result;//return the result
        
    }
};