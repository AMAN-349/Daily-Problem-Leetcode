class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        //here find all valid subaarays for each index and as we know in subarray
        //consider subarrays ending at each index

        long long ans=0;
        vector<vector<int>> conflict(n+1);
        vector<long long> extra(n+1,0);
        for(auto &p: conflictingPairs)
        {
            int a=min(p[0],p[1]);
            int b=max(p[0],p[1]);
            conflict[b].push_back(a);
        }
        int maxconflict=0;
        int secondconflict=0;
        for(int i=1;i<=n;i++)
        {
            for(int &u:conflict[i])
            {
                if(u>=maxconflict)
                {
                    secondconflict=maxconflict;
                    maxconflict=u;
                }
                else if(u>secondconflict){
                    secondconflict=u;
                }

            }
            ans+=(i-maxconflict);
            extra[maxconflict]+=maxconflict-secondconflict;
        }
        long long maxi=0;
        for(auto i:extra)
        {
            maxi=max(maxi,i);
        }
        return ans+maxi;

    }
};