class Solution {
public:

    int m;
    int find(vector<int> v)
    {
        sort(v.begin(),v.end(),greater<int>());
        int ans=0;
        for(int i=0;i<m;i++)
        {
            ans=max(ans,v[i]*(i+1));
        }
        return ans;
    }

    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        m=matrix[0].size();
        vector<int> v=matrix[0];
        int ans=0;
        ans=max(ans,find(v));
        for(int i=1;i<n;i++)
        {
            vector<int> temp(m,0);
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==1)
                {
                    if(matrix[i][j]==1)
                    {
                        temp[j]=matrix[i][j]+v[j];
                    }
                    else{
                        temp[j]=matrix[i][j];
                    }
                }
            }
            v=temp;
            ans=max(ans,find(v));
        }
        return ans;
    }
};