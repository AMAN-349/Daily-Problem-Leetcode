class Solution {
public:
    long long getDescentPeriods(vector<int>& nums) {
        int n=nums.size();
        long long len=1;
        long long ans=0;
        for(int i=1;i<n;i++)
        {
            if((nums[i]+1)==nums[i-1])
            {
                len++;
            }
            else{
                ans+=(len*(len+1)*1LL)/2;
                len=1;
            }
        }
        ans+=(len*(len+1)/2);
        return ans;
    }
};