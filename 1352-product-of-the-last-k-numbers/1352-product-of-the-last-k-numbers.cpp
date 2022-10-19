class ProductOfNumbers {
public:
    vector<int>prefix;
    int product = 1;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num == 0)
        {
            prefix.clear();
            product = 1;
        }
        else
        {
            product = product * num;
            prefix.push_back(product);
        }
    }
    
    int getProduct(int k) {
        if(k > prefix.size() )
        {
            return 0;
        }
        else if( k == prefix.size())
        {
            return prefix[prefix.size()-1];
        }
        else
        {
            return prefix[prefix.size()-1] / prefix[prefix.size()-1-k];
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */