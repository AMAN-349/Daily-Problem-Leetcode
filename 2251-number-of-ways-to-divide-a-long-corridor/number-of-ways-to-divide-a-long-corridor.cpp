class Solution {
public:
    int numberOfWays(string corridor) {
        int n=corridor.size();
        int cnt=0;
        int res=0;
        int ans=1;
        int cnts=0;
        int flag=0;
        long long mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            if(corridor[i]=='S')
            {
                cnts++;
                cnt++;
                if(cnt==2)
                {
                    flag=1;
                    int j=i+1;
                    while (++i < corridor.size() && corridor[i] != 'S') { 
                        res++;  
                    }
                    if (i < corridor.size()) {  
                        ans = (1LL * ans * (res + 1)) % mod;  
                    }
                    res = 0; 
                    cnt = 0;
                    i--; 
                }
            }
        }
        if(!flag) return 0;
        return (cnts % 2 == 0) ? ans : 0;
    }
};