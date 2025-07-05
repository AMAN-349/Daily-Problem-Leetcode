class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int find=-(nums[i]);
            int l=i+1;
            int r=n-1;
            while(l<r)
            {
                if(nums[l]+nums[r]<find)
                {
                    l++;
                }
                else if(nums[l]+nums[r]>find)
                {
                    r--;
                }
                else{
                    if(nums[l]==nums[r])
                    {
                        ans.push_back({nums[i],nums[l],nums[r]});
                        break;
                    }
                    else{
                        int temp=nums[l];
                        int temp2=nums[r];
                        ans.push_back({nums[i],nums[l],nums[r]});
                        while(nums[l]==temp)
                        {
                            l++;
                        }
                        while(nums[r]==temp2)
                        {
                            r--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};