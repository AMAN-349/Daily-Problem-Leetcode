class Solution {
public:
    bool validMountainArray(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
        {
            return false;
        }
        int i=max_element(nums.begin(),nums.end())-nums.begin();
        int maxi=nums[i];
        bool flag1=false;
        for(int j=i-1;j>=0;j--)
            {
                if(nums[j]>=maxi)
                {
                    return false;
                }
                maxi=nums[j];
                flag1=true;
            }
        bool flag2=false;
        maxi=nums[i];
        for(int j=i+1;j<n;j++)
            {
                if(nums[j]>=maxi)
                {
                    return false;
                }
                flag2=true;
                maxi=nums[j];
            }
        return flag1 && flag2;
    }
};