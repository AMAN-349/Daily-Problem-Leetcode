class Solution {
public:
    vector<int> v;
    int n;
    Solution(vector<int>& w) {
        n=w.size();
        v.push_back(w[0]);
        for(int i=1;i<n;i++)
        {
            v.push_back(v[i-1]+w[i]);
        }
    }
    
    int pickIndex() {
        int sum=v.back();
        int ind=rand()%sum;
        return upper_bound(v.begin(),v.end(),ind)-v.begin();   
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */