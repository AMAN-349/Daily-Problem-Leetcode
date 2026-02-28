class Solution {
public:
    int concatenatedBinary(int n) {
        long long sum=1;
        long long mod=1e9+7;
        for(int i=2;i<=n;i++)
        {
            long long temp=log2(i)+1;
            sum<<=temp;
            sum|=i;
            sum=sum%mod;
        }
        return sum;
    }
};