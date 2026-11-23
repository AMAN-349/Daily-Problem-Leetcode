class ProductOfNumbers {
public:
    vector<int> v;
    ProductOfNumbers() {
        //vector<int> v;
    }
    
    void add(int num) {
        if(num==0)
        {
            v.clear();
            return;
        }
        if(v.size()==0)
        {
            v.push_back(num);
        }
        else{
            v.push_back(v.back()*num);
        }
    }
    
    int getProduct(int k) {
        if(v.size()<k) return 0;
        if(v.size()==k) return v[v.size()-1];
        cout<<v[v.size()-1]<<" ";
        return v[v.size()-1]/v[v.size()-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */