class Solution {
public:
    long long mod = 1e9 + 7;

    vector<long long> fact;

    void precompute() {
        fact[0] = 1;
        for (int i = 1; i < fact.size(); i++) {
            fact[i] = (fact[i-1] * i) % mod;
        }
    }

    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    long long findncr(long long n, long long r) {
        long long numerator = fact[n];
        long long denom = (fact[r] * fact[n - r]) % mod;

        return (numerator * power(denom, mod - 2)) % mod;
    }

    int countVisiblePeople(int n, int pos, int k) {
        long long ans=0;
        fact.resize(n);
        precompute();

        if(k==0) return 2;

        for(int i=0;i<=k;i++)
        {
            int l=i;
            int r=k-i;
            long long res=1;

            int cnt=0;
            if(pos>=l)
            {
                if(pos-1>=0)
                res*=findncr(pos,l);
                cnt++;
            }

            if(n-pos-1>=r)
            {
                if(pos+1<=n)
                res*=findncr(n-pos-1,r);
                cnt++;
            }
            if(cnt==2){
                ans=(ans%mod + res%mod)%mod;
            }
        }

        return (ans % mod *2 %mod)%mod;
    }
};