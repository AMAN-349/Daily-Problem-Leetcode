class Solution {
public:
    int findNthDigit(int n) {
        long long total=0;
        long long digit=1;
        long long base=9;
        while(total+digit*base<n)
        {
            total+=digit*base;
            base*=10;
            digit++;
        }
        n=n-total;
        int num=pow(10,digit-1);
        num+=(n-1)/digit;
        int index=(n-1)%digit;
        string s=to_string(num);
        return s[index]-'0';
    }
};