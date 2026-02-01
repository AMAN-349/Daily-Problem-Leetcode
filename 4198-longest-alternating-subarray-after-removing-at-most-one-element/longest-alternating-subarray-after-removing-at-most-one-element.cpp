class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int n=nums.size(), ans=1;
        vector<vector<int>> dpPre(n, vector<int>(2, 1)), dpPst(n, vector<int>(2, 1));
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                dpPre[i][0]+=dpPre[i-1][1];
            }else if(nums[i-1]<nums[i]){
                dpPre[i][1]+=dpPre[i-1][0];
            }
            ans=max({ans, dpPre[i][0], dpPre[i][1]});
        }
        for(int i=n-2;i>=1;i--){
            if(nums[i]<nums[i+1]){
                dpPst[i][1]+=dpPst[i+1][0];
            }else if(nums[i]>nums[i+1]){
                dpPst[i][0]+=dpPst[i+1][1];
            }
            ans=max({ans, dpPst[i][0], dpPst[i][1]});
        }
        for(int i=1;i<n-1;i++){
            if(nums[i-1]<nums[i+1]) ans=max(dpPre[i-1][0]+dpPst[i+1][0], ans);
            if(nums[i-1]>nums[i+1]) ans=max(dpPre[i-1][1]+dpPst[i+1][1], ans);
        }
        return ans;
    }
};