class Solution {
public:

    bool isposs(int m,vector<int>& piles,int k)
    {
        long long ans=0;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]<=m)
            {
                ans++;
            }
            else{
                ans+=(piles[i]/m)*1LL;
                ans+=(piles[i]%m)==0?0:1;
            }
        }
        return ans<=k;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int mini=1;
        int maxi=INT_MIN;
        for(auto i:piles)
        {
            mini=min(mini,i);
            maxi=max(maxi,i);
        }
        int ans=0;
        while(mini<=maxi)
        {
            int m=(mini+maxi)/2;
            if(isposs(m,piles,h))
            {
                ans=m;
                maxi=m-1;
            }
            else{
                mini=m+1;
            }
        }
        return ans;
    }
};