class MyHashSet {
    private : 
    const int size = 100; 
    vector<int> hash[100];
public:
    MyHashSet() {
    
    }

    void add(int key) { 
        int index = key % size;
        if(contains(key) == false)
        {
            hash[index].push_back(key);   
        }
    }

    void remove(int key) 
    {
        int index = key % size;
        for(int i = 0; i < hash[index].size(); i++)
        {
            if(hash[index][i] == key) 
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
            if(hash[index][i] == key) 
            {
                return true; 
            }
        }
        return false;
    }
};
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */