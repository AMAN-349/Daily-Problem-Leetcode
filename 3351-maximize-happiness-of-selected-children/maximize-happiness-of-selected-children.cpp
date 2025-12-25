class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        long long ans=0;
        int cnt=0;
        sort(happiness.begin(),happiness.end(),greater<int>());
        int i=0;
        while(i<n && k--)
        {
            ans+=max(0,happiness[i]-cnt);
            cnt++;
            i++;
        }
        return ans;
    }
};