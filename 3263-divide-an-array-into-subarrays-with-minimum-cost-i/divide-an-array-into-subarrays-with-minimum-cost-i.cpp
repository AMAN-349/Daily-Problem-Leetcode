class Solution {
public:
    int n;
    int find(int i,vector<int>& nums,int k)
    {
        if(k==1)
        {
            return nums[i];
        }
        int ans=INT_MAX;
        for(int j=i;j<=n-k;j++)
        {
            ans=min(ans,nums[i]+find(j+1,nums,k-1));
        }
        return ans;
    }

    int minimumCost(vector<int>& nums) {
        n=nums.size();
        return find(0,nums,3);
    }
};