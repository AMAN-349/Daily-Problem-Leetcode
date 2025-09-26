class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if (nums[i] == 0) continue;
            for(int j=i+1;j<n;j++)
            {
                int pos=nums[i]+nums[j];
                int res=lower_bound(nums.begin()+j,nums.end(),pos)-nums.begin();
                ans+=res-j-1;
            }
        }
        return ans;
    }
};