class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int m=0;
        int r=n-1;
        while(m<=r)
        {
            if(nums[m]==1)
            {
                m++;
            }
            else if(nums[m]==0)
            {
                swap(nums[l],nums[m]);
                m++;
                l++;
            }
            else{
                swap(nums[m],nums[r]);
                r--;
            }
        }

    }
};