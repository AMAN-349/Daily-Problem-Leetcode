class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for (int bit = 0; bit < 32; bit++)
        {
            int cnt=0;
            for(auto i:nums)
            {
                if((i>>bit)&1)
                {
                    cnt++;
                }
            }
            if(cnt%3!=0)
            {
                ans|=(1<<bit);
            }
        }
        return ans;
    }
};