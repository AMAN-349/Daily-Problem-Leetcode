class Solution {
public:

    int sum(int a,int b)
    {
        while (b != 0)
        {
            int carry=(a&b)<<1;
            a=a^b;
            b=carry;
        }
        return a;
    }

    int sub(int a, int b) {
        int borrow = 0;
        int ans = 0;
        int bitPos = 1;

        while (a > 0 || b > 0) {
            int bitA = a & 1;
            int bitB = b & 1;

            int diff = bitA - bitB - borrow;

            if (diff < 0) {
                diff += 2;
                borrow = 1;
            } else {
                borrow = 0;
            }

            ans += diff * bitPos;

            bitPos <<= 1;
            a >>= 1;
            b >>= 1;
        }
        return ans;
    }

    int getSum(int a, int b) {
        if (a == 0) return b;
        if (b == 0) return a;

        if (a > 0 && b > 0)
            return sum(a, b);

        if (a < 0 && b < 0)
            return -sum(abs(a), abs(b));

        if (abs(a) > abs(b)) {
            int res = sub(abs(a), abs(b));
            return a > 0 ? res : -res;
        } else {
            int res = sub(abs(b), abs(a));
            return b > 0 ? res : -res;
        }
    }
};
