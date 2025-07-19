class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0]=1;
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0)
            {
                rem+=k;
            }
            ans+=m[rem];
            m[rem]++;
        }
        return ans;
    }
};