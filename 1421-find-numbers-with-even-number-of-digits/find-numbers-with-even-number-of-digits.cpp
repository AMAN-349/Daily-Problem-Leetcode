class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            int ans=floor(log10(nums[i]))+1;
            if(ans%2==0)
            {
                cnt++;
            }
        }
        return cnt;
    }
};