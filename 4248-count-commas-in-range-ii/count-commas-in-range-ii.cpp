class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        int comma=1;
        for(long long i=1000;i<=n;i*=1000)
        {
            ans+=((n/i)-1)*i;
            ans+=(n%i)+1;
            comma++;
        }
        return ans;
    }
};