class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int temp = (1 << i); 
            
            if (n & temp) { 
                if (prev == -1) {
                    prev = i; 
                } else {
                    ans = max(ans, i - prev);
                    prev = i;
                }
            }
        }
        return ans;
    }
};