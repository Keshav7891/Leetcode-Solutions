class Solution {
public:

    vector<int> getOrder(vector<vector<int>>& Tasks) {
        int n = Tasks.size();
        vector<pair<int,int>> arr;
        for(int i=0; i<n; i++)
            arr.push_back({Tasks[i][0],i});
        sort(arr.begin(),arr.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int time = 0;
        vector<int> ans;
        pair<int,int> task;

        for(int i=0; i<n; i++) {
            while(!pq.empty() && time < arr[i].first) {
                task = pq.top();
                pq.pop();
                time += task.first;
                ans.push_back(task.second);
            }
            time = max(time,arr[i].first);
            pq.push({Tasks[arr[i].second][1],arr[i].second});
        }
        while(!pq.empty()) {
            task = pq.top();
            pq.pop();
            ans.push_back(task.second);
        }

        return ans;
    }
};