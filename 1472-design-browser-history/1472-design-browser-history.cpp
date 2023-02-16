class BrowserHistory {
public:
    stack<string>s;    //for the forward
    stack<string>curr;
    BrowserHistory(string homepage) {
        curr.push(homepage);
    }
    
    void visit(string url) {
        while(s.empty()==false) s.pop();
        curr.push(url);
    }
    
    string back(int steps) {
        while(curr.size() > 1 && steps != 0)
        {
            string top = curr.top();
            curr.pop();
            s.push(top);
            steps--;
        }
        return curr.top();
        
    }
    
    string forward(int steps) {
        while(s.size()> 0 && steps != 0)
        {
            string top = s.top();
            s.pop();
            curr.push(top);
            steps--;
        }
        return curr.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */