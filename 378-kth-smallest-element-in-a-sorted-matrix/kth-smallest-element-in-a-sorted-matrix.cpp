class Solution {
public:

    int find(int m,vector<vector<int>>& v)
    {
        int ans=0;
        for(auto i:v)
        {
            ans+=upper_bound(i.begin(),i.end(),m)-i.begin();
        }
        return ans;

    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            mini=min(mini,matrix[i][0]);
            maxi=max(maxi,matrix[i][m-1]);
        }

        while(mini<=maxi)
        {
            int m=(mini+maxi)/2;
            if(find(m,matrix)<k)
            {
                mini=m+1;
            }
            else{
                ans=m;
                maxi=m-1;
            }
        }
        return ans;

    }
};