class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // use median also if want;
        int ans=0;
        int l=0;
        sort(nums.begin(),nums.end());
        int r=nums.size()-1;
        while(l<r)
        {
            ans+=abs(nums[r]-nums[l]);
            l++;
            r--;
        }
        return ans;
    }
};