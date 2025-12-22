class Solution {
public:
    long long lastInteger(long long n) {
        long long start=1;
        long long end=n;
        long long cd=1;
        int dir=0;
        while(start<end)
        {
            if(dir==0)
            {
                if(n%2==0)
                {
                    end=end-cd;
                }
                dir=1;
            }
            else{
                if(n%2==0)
                {
                    start=start+cd;
                }
                dir=0;
            }
            if(n%2==0) n=n/2;
            else n=n/2+1;
            cd*=2;
        }
        return start;
    }
};