class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diff=nums;
        for(int i=1;i<nums.size();i++)
        {
            diff[i]=nums[i]-nums[i-1];
        }
        int l,r;
        for(auto i: queries)
        {
            vector<int> v=i;
            l=v[0];
            r=v[1];
            diff[l]-=1;
            if(r+1<nums.size())
            {
                diff[r+1]+=1;
            }
        }
        if(diff[0]>0) return false;
        for(int i=1;i<nums.size();i++)
        {
            diff[i]+=diff[i-1];
            if(diff[i]>0)
            {
                return false;
            }
        }
        return true;
    }
};