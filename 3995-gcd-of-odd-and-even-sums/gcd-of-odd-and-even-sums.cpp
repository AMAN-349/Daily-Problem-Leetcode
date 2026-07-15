class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sn1=n/2.0*(2+((n-1)*2));
        int sn2=n/2.0*(4+((n-1)*2));

        return __gcd(sn1,sn2);
    }
};