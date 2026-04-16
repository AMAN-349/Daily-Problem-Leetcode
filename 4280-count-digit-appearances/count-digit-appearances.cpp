class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans=0;
        for(auto i:nums)
        {
            while(i>0)
            {
                int rem=i%10;
                if(rem==digit)
                {
                    ans++;
                }
                i=i/10;
            }
        }
        return ans;
    }
};