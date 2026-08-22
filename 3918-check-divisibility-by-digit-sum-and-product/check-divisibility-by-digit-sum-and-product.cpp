class Solution {
public:
    bool checkDivisibility(int n) {
        string temp=to_string(n);
        int sum=0;
        int prod=1;
        for(auto i:temp)
        {
            sum+=(i-'0');
        }
        for(auto i:temp)
        {
            prod*=(i-'0');
        }
        sum+=prod;
        return n%sum==0;
    }
};