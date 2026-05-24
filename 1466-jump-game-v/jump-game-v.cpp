class Solution {
public:
    int n;
    vector<int> dp;

    int find(int ind,vector<int>& arr,int d)
    {
        if(dp[ind]!=-1) return dp[ind];
        int ans=1;
        for(int i=ind+1;i<=min(n-1,ind+d);i++)
        {
            if(arr[i] >= arr[ind])
                break;

            ans = max(ans, 1 + find(i, arr, d));
        }

        for(int i=ind-1;i>=max(0,ind-d);i--)
        {
            if(arr[i] >= arr[ind])
                break;

            ans = max(ans, 1 + find(i, arr, d));
        }
        return dp[ind]=ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        n=arr.size();
        dp.resize(n+1,-1);
        int ans=1;

        for(int i=0;i<n;i++)
        {
            int ansi=find(i,arr,d);
            ans=max(ans,ansi);
        }

        return ans;
    }
};