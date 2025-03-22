class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;
        int ans = 1;  
        int cnts = 0; 
        int res = 0;
        int flag=0;  

        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                cnts++;
                flag=1;
                if (cnts == 2) {  
                    while (++i < corridor.size() && corridor[i] != 'S') { 
                        res++;  
                    }
                    if (i < corridor.size()) {  
                        ans = (1LL * ans * (res + 1)) % MOD;  
                    }
                    res = 0; 
                    cnts = 0;
                    i--; 
                }
            }
        }
        if(!flag) return 0;
        return (cnts % 2 == 0) ? ans : 0;
    }
};
