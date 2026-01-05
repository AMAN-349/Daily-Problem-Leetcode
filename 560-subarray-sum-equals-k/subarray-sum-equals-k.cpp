class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        m[0]=1;
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int tofind=sum-k;
            if(m.find(tofind)!=m.end())
            {
                ans+=m[tofind];
            }
            m[sum]++;
        }
        return ans;
    }
};