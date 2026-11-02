class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int idx=n/2;
        int ans=0;
        for(auto i:nums)
        {
            ans+=abs(i-nums[idx]);
        }
        return ans;
    }
};