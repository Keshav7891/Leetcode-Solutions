class RandomizedSet {
public:
    unordered_map<int,int>m;
    vector<int>nums;
    int index = 0;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val)!=m.end())
        {
            //cout<<val<<endl;
            return false;
        }
        else
        {
            nums.push_back(val);
            m[val] = nums.size()-1;
            return true;
        }
    }
    
    bool remove(int val) {
        if(m.find(val)!=m.end())
        {
            int last_ele = nums[nums.size()-1];
            int i = m[val];
            swap(nums[i],nums[nums.size()-1]);
            nums.pop_back();
            m[last_ele] = i;
            m.erase(val);
            return true;   
        }
        else
        {
            return false;
        }
    }
    
    int getRandom() {
        int rndm = rand() % nums.size();
        return nums[rndm];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */