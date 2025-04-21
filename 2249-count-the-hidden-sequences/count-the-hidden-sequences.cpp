class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n=differences.size();
        vector<long long> prefix(n+1,0);
        prefix[0]=0;
        for(int i=1;i<=n;i++)
        {
            prefix[i]=prefix[i-1]+differences[i-1];
        }
        int mini=*min_element(prefix.begin(),prefix.end());
        int maxi=*max_element(prefix.begin(),prefix.end());
        int ans=(upper-lower+1)-(maxi-mini);
        if(ans<0)
        {
            return 0;
        }
        return ans;
    }
};