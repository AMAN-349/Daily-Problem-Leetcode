class Solution {
public:
    int finalElement(vector<int>& nums) {
        int n=nums.size();
        int ind=max_element(nums.begin(),nums.end())-nums.begin();
        int maxi=nums[ind];
        int start=0;
        int end=n-1;
        if(ind==0 || ind==n-1)
        {
            return maxi;
        }
        return max(nums[0],nums[n-1]);
    }
};