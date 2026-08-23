class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int lq = 0; 
        int rq = 0; 
        int lsum = 0;
        int rsum = 0;
        
        for(int i = 0; i < n / 2; i++) {
            if(num[i] != '?') {
                lsum += (num[i] - '0');
            } else {
                lq++;
            }
        }
        
        for(int i = n / 2; i < n; i++) {
            if(num[i] != '?') {
                rsum += (num[i] - '0');
            } else {
                rq++;
            }
        }
        
        if((lq + rq) % 2 != 0) {
            return true;
        }
        return (lsum - rsum) != (rq - lq) * 9 / 2; 
    }
};