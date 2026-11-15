class Solution {
public:
    long long mod=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        long long oddcnt=0;
        long long evencnt=0;

        int sum=0;
        long long ans=0;

        for(auto i:arr)
        {
            sum+=i;

            if(sum%2==0)
            {
                evencnt++;
                ans+=oddcnt;
            }
            else{
                oddcnt++;
                ans=(ans+evencnt)%mod;
                ans=(ans+1)%mod;
            }
        }
        return ans;
    }
};