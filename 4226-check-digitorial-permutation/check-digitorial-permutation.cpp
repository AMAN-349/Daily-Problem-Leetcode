class Solution {
public:

    long long fact(int n)
    {
        if(n<=1)
        {
            return 1;
        }
        return 1LL*n*fact(n-1);
    }

    bool isDigitorialPermutation(int n) {
        long long sum=n;
        long long ans=0;
        while(n>0)
        {
            int temp=(n%10);
            ans+=fact(temp);
            n=n/10;
        }
        cout<<ans<<" ";

        string s1 = to_string(sum);
        string s2 = to_string(ans);

        if (s1.length() != s2.length()) return false;

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        return s1 == s2;
        
    }
};