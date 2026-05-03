class Solution {
public:

    bool isprime(int n)
    {
        if(n<=1) return false;
        if(n==2) return true;
        for(int i=2;i<n;i++)
        {
            if(n%i==0) return false;
        }
        return true;
    }

    int sumOfPrimesInRange(int n) {
        int num1=n;
        int num2=0;
        while(n>0)
        {
            num2=(num2*10+(n%10));
            n=n/10;
        }
        int ans=0;
        int start=min(num1,num2);
        int end=max(num1,num2);
        for(int i=start;i<=end;i++)
        {
            if(isprime(i))
            {
                ans+=i;
            }
        }
        return ans;
    }
};