class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        vector<long long> prefix(n,0);
        vector<long long> pricepref(prices.begin(),prices.end());
        for(int i=1;i<n;i++)
        {
            pricepref[i]+=pricepref[i-1];
        }
        for(int i=0;i<n;i++)
        {
            prefix[i]=prices[i]*strategy[i];
        }
        for(int i=1;i<n;i++)
        {
            prefix[i]+=prefix[i-1];
        }
        long long ans=prefix[n-1];
        int i=0;
        int j=k-1;
        int mid=k/2;
        while(j<n)
        {
            long long left=(i>0)?prefix[i-1]:0;
            long long suffix=prefix[n-1]-prefix[j];
            long long temp=pricepref[j]-pricepref[j-mid];
            ans=max(ans,left+suffix+temp);
            i++;
            j++;
        }
        return ans;
    }
};