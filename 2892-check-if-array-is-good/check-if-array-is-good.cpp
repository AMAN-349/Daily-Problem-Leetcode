class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        for(i=0;i<n-1;i++)
        {
            if(nums[i]-i!=1)
            {
                return false;
            }
        }
        if(nums[i]!=n-1)
        {
            return false;
        }
        return true;
    }
};