class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int curr=0;
        int ans=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            curr+=nums[i];
            int rem=sum-curr;
            if(abs(curr-rem)%2==0)
            {
                ans++;
            }
        }
        return ans;
    }
};