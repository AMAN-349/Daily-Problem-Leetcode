class Solution {
public:

    vector<vector<int>> find(int i,vector<int>& nums, vector<vector<int>>& ans)
    {
        if(i==nums.size()-1)
        {
            ans.push_back(nums);
            return ans;
        }
        vector<int> temp(20,0);
        for(int idx=i;idx<nums.size();idx++)
        {
            if(!temp[nums[idx]+10]){
                temp[nums[idx]+10]=1;
            swap(nums[i],nums[idx]);
            find(i+1,nums,ans);
            swap(nums[i],nums[idx]);
            }
        }
        return ans;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        return find(0,nums,ans);
    }
};