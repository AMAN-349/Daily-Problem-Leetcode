class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end(),greater<int>());
        long long ans=0;

        for(int i=0;i<k;i++)
        {
            long long temp1=1LL*nums[i]*mul;
            long long temp2=nums[i];

            if(temp1>temp2)
            {
                ans+=temp1;
                mul--;
            }
            else{
                ans+=temp2;
            }
        }

        return ans;
    }
};