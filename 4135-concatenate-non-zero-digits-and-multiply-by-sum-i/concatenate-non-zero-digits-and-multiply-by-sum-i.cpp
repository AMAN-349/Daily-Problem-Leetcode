class Solution {
public:
    long long sumAndMultiply(int n) {
        string s;
        while(n>0)
            {
                int d=n%10;
                if
                    (d!=0) s+=char('0'+ d);
                n /= 10;
                
            }
        if(s.size()==0)
        {
            s="0";
        }
        reverse(s.begin(),s.end());
        
        long long sum=0;
        for(auto i:s)
            {
                sum+=(i-'0');
            }
        long long no=stoll(s);
        return no*sum;
    }
};