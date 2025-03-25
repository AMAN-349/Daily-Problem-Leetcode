class Solution {
public:
    int cntbits(int n) {
        int cnt = 0;
        while (n > 0) {
            n = n & (n - 1);
            cnt++;
        }
        return cnt;
    }

    int minimizeXor(int num1, int num2) {
        int cnt1 = cntbits(num1);
        int cnt2 = cntbits(num2);
        
        if (cnt1 == cnt2) {
            return num1;
        }

        int ans = num1;

        
        if (cnt2 > cnt1) {
            int diff = cnt2 - cnt1;
            int i = 0;
            while (diff && i < 32) {
                if (!(ans & (1 << i))) { 
                    ans |= (1 << i);
                    diff--;
                }
                i++;
            }
        }
        else {
            int diff = cnt1 - cnt2;
            int i = 0;
            while (diff && i < 32) {
                if (ans & (1 << i)) { 
                    ans &= ~(1 << i);
                    diff--;
                }
                i++;
            }
        }

        return ans;
    }
};