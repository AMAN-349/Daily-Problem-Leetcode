class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxi=INT_MIN,mini=INT_MAX;
        for (auto val : nums) {
            maxi=max(maxi,val);
            mini=min(mini,val);
        }
        vector<int> m(maxi+1,0);
        for (auto val : nums) {
            m[val]++;
        }
        for(int i=1;i<=maxi;i++)
        {
            m[i]+=m[i-1];
        }

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;

        for (int curr=mini;curr<=maxi;curr++) {
            int left = max(curr-k,mini);
            int right=min(curr+k,maxi);
            int f=m[curr]-m[curr-1];
            int extra=min(numOperations,m[right]-m[left-1]-f);
            res=max(res,extra+f);
        }

        return res;
    }
};
