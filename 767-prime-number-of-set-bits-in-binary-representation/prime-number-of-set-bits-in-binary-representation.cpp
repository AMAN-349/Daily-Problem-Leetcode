class Solution {
public:

    int find(int n)
    {
        int cnt=0;
        while(n)
        {
            cnt++;
            n=(n&(n-1));
        }
        return cnt;
    }

    bool isprime(int n)
    {
        if(n<2) return false;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                return false;
            }
        }
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int cnt=0;
        for(int i=left;i<=right;i++)
        {
            int bits=find(i);
            if(isprime(bits))
            {
                cnt++;
            }
        }
        return cnt;
    }
};