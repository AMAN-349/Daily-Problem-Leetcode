class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int i=1;
        int cnt1=0,cnt2=0,cnt3=0;
        while(i<n && nums[i]>nums[i-1])
        {
            cnt1=1;
            i++;
        }
        while(i>0 && i<n && nums[i]<nums[i-1])
        {
            cnt2=1;
            i++;
        }
        while(i>0 && i<n && nums[i]>nums[i-1])
        {
            cnt3=1;
            i++;
        }
        return (cnt1+cnt2+cnt3)==3 && i==n;
    }
};