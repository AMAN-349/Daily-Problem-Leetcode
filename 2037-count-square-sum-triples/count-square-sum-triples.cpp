class Solution {
public:
    int countTriples(int n) {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int total=(i*i)+(j*j);
                int rem=sqrt(total);
                if(rem*rem==total)
                {
                    if(rem<=n)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};