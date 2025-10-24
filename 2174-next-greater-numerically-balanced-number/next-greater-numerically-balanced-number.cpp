class Solution {
public:

    bool isbal(int i)
    {
        map<int,int> m;
        while(i>0)
        {
            int rem=i%10;
            m[rem]++;
            i=i/10;
        }
        for(auto i:m)
        {
            if(i.first!=i.second)
            {
                return false;
            }
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        for(int i=n+1;i<=1666666;i++)
        {
            if(isbal(i))
            {
                return i;
            }
        }
        return -1;
    }
};