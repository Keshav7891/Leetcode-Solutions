class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int>res;
        deque<int>dq;
        sort(deck.begin(),deck.end());
        for(int i=deck.size()-1;i>=0;i--)
        {
            if(dq.size()>=2)
            {
                int ele = dq.back();
                dq.push_front(ele);
                dq.pop_back();
                //cout<<ele<<endl;
            }
            dq.push_front(deck[i]);
        }
        while(dq.empty()==false)
        {
            int ele = dq.front();
            dq.pop_front();
            res.push_back(ele);
        }
        return res;
    }
};