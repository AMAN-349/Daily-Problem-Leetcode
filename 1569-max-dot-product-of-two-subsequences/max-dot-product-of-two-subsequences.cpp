class Solution {
public:
    vector<vector<int>> dp;
    int find(int i,int j,int n,int m,vector<int>& nums1,vector<int>& nums2,bool flag)
    {
        if(i==n || j==m)
        {
            return INT_MIN;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=nums1[i]*nums2[j];
        int temp=find(i+1,j+1,n,m,nums1,nums2,true);
        if(temp!=INT_MIN)
        {
            ans=max(ans,ans+temp);
        }
        ans=max(ans,find(i+1,j,n,m,nums1,nums2,flag));
        ans=max(ans,find(i,j+1,n,m,nums1,nums2,flag));
        return dp[i][j]=ans;
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        int i=0;
        int j=0;
        return find(i,j,n,m,nums1,nums2,false);
    }
};