class MyHashMap {
private : 
    const int size = 100; 
    vector<pair<int,int>> hash[100];
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value)
    {
        int index = key % size;
        if(contains(key) == false)
        {
            hash[index].push_back({key,value});   
        }
        else
        {
            for(int i = 0; i < hash[index].size(); i++)
            {
                if(hash[index][i].first == key) 
                {
                    hash[index][i].second = value;
                }
            }
        }
    }
    
    int get(int key)
    {
        int index = key%size;
        for(int i = 0; i < hash[index].size(); i++)
        {
            if(hash[index][i].first == key) 
            { 
                return hash[index][i].second;
            }   
        }
        return -1;
    }
    
    void remove(int key) {
        int index = key % size;
        for(int i = 0; i < hash[index].size(); i++)
        {
            if(hash[index][i].first == key) 
            { 
                hash[index].erase(hash[index].begin() + i); 
                break; 
            }   
        }
    }
    
    bool contains(int key) 
    {
        int index = key % size;
        for(int i = 0; i < hash[index].size(); i++)
        {
            if(hash[index][i].first == key) 
            {
                return true; 
            }
        }
        return false;
    }
    
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */