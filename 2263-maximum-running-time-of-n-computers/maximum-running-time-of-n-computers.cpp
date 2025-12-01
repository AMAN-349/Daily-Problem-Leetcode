class Solution {
public:

    bool check(long long mid, int n, vector<int>& batteries) {
        long long power = 0;
        long long tocmp=mid*n;
        long long curr=0;
        for(auto i:batteries)
        {
            curr+=min(i*1LL,mid);
        }
        return curr>=tocmp;
    }


    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = accumulate(batteries.begin(), batteries.end(), 0LL);
        long long l = 0;
        long long r = sum / n;
        long long ans = 0;

        while(l<=r)
        {
            long long m = l + (r - l) / 2;   
            if(check(m,n,batteries))
            {
                ans=m;
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return ans;
    }
};