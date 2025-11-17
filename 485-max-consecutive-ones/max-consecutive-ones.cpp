class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int temp=0;
        int ans=0;
        for(auto i:nums)
        {
            if(i==1)
            {
                temp++;
            }
            else{
                ans=max(ans,temp);
                temp=0;
            }
        }
        ans=max(ans,temp);
        return ans;
    }
};