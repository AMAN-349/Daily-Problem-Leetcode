class FindSumPairs {
public:
    vector<int> v1;
    vector<int> v2;
    map<int,int> m;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1=nums1;
        v2=nums2;
        for(int i=0;i<v2.size();i++)
        {
            m[v2[i]]++;
        }
    }
    
    void add(int index, int val) {
        m[v2[index]]--;             
        v2[index] += val;            
        m[v2[index]]++;
    }
    
    int count(int tot) {
        int ans=0;
        for(int i=0;i<v1.size();i++)
        {
            ans+=m[tot-v1[i]];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */