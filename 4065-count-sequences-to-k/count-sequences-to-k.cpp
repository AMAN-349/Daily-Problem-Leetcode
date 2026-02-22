class Solution {
public:
    int n;
    map<tuple<int,long long,long long>, int> dp;

    pair<long long,long long> solve(long long i,long long j)
    {
        long long hcf=__gcd(i,j);
        i=i/hcf;
        j=j/hcf;
        return {i,j};
    }

    long long find(long long num,long long den,int i,vector<int>& nums,long long& k)
    {
        if (i == n) {
            if (den == 1 && num == k) {
                return 1;
            }
            return 0;
        }
        auto key = make_tuple(i, num, den);
        if (dp.count(key)) return dp[key];

        long long ans=0;
        ans+=find(num,den,i+1,nums,k);

        auto it=solve(num*nums[i],den);
        ans+=find(it.first,it.second,i+1,nums,k);

        auto it2=solve(num,den*nums[i]);
        ans+=find(it2.first,it2.second,i+1,nums,k);

        return dp[key]=ans;
    }

    int countSequences(vector<int>& nums, long long k) {
        n=nums.size();
        dp.clear();
        return find(1,1,0,nums,k);
    }
};