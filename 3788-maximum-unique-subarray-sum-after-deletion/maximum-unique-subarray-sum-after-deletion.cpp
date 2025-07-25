class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        if(maxi<0)
        {
            return maxi;
        };
        set<int> s(nums.begin(),nums.end());
        int ans=0;
        for(auto i:s)
        {
            if(i>0)
            {
                ans+=i;
            }
        }
        return ans;
    }
};