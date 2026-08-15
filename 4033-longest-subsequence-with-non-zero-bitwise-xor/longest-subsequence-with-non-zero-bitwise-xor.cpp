class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(auto i:nums)
        {
            ans^=i;
        }
        if(ans!=0)
        {
            return n;
        }
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        if(sum==0)
        {
            return 0;
        }
        return n-1;
    }
};