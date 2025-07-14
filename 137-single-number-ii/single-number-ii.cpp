class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        long long mask=(1L<<31);
        int ans=0;
        while(mask)
        {
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                if((mask)&(nums[i]))
                {
                    cnt++;
                }
            }
            if(cnt%3!=0)
            {
                ans=(ans|mask);
            }
            mask=(mask>>1);
        }
        return ans;
    }
};