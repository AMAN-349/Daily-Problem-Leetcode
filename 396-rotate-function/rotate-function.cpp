class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> v;
        vector<int> prefsum(n,0);
        vector<int> suffsum(n,0);
        prefsum[0]=nums[0];
        suffsum[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            prefsum[i]=nums[i]+prefsum[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            suffsum[i]=nums[i]+suffsum[i+1];
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=(i*nums[i]);
        }
        int res=ans;
        for(int i=n-1;i>0;i--)
        {
            int temp=ans;
            if((i+1)<n)
            {
                temp+=suffsum[i+1];
            }
            temp+=prefsum[i-1];
            temp-=(nums[i]*(n-1));
            ans=temp;
            res=max(res,ans);
        }
        return res;
    }
};