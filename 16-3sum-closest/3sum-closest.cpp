class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int diff=INT_MAX;
        int ans;
        for(int i=0;i<n;i++)
        {
            int find=target-nums[i];
            int l=i+1;
            int r=n-1;
            while(l<r)
            {
                int res=nums[l]+nums[r];
                if(abs(find-res)<diff)
                {
                    ans=res+nums[i];
                    diff=abs(find-res);
                }
                if(res<find)
                {
                    l++;
                }
                else if(res>find)
                {
                    r--;
                }
                else{
                    ans=nums[i]+nums[l]+nums[r];
                    break;
                }
            }
        }
        return ans;
    }
};