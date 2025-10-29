class Solution {
public:
    int smallestNumber(int n) {
        if(n&(n+1)==0) return n;
        vector<int> v={1,2,4,8,16,32,64,128,256,512,1024};
        int ans=upper_bound(v.begin(),v.end(),n)-v.begin();
        return v[ans]-1;
    }
};