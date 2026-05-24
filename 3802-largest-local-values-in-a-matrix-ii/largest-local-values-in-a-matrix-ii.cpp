class Solution {
public:
    int n,m;
    bool check(int row,int col,vector<vector<int>>& matrix,vector<vector<vector<int>>>& prefix)
    {
        int val=matrix[row][col];

        int topr=max(0,row-val);
        int botr=min(row+val,n-1);

        int lc=max(0,col-val);
        int rc=min(m-1,col+val);

        vector<int> total=prefix[botr][rc];
        vector<int> left;
        vector<int> right;
        vector<int> extra;

        if(lc>0)
        {
            left=prefix[botr][lc-1];
        }
        if(topr>0)
        {
            right=prefix[topr-1][rc];
        }
        if(topr>0 && lc>0)
        {
            extra=prefix[topr-1][lc-1];
        }
        if(!left.empty())
        {
            for(int i=0;i<=200;i++)
            {
                total[i]-=left[i];
            }
        }
        if(!right.empty())
        {
            for(int i=0;i<=200;i++)
            {
                total[i]-=right[i];
            }
        }
        if(!extra.empty())
        {
            for(int i=0;i<=200;i++)
            {
                total[i]+=extra[i];
            }
        }
        if((row-val)>=0 && (col-val)>=0)
        total[matrix[row-val][col-val]]--;

        if(row-val>=0 && col+val<m)
        total[matrix[row-val][col+val]]--;

        if(row+val<n && col-val>=0)
        total[matrix[row+val][col-val]]--;

        if(row+val<n && col+val<m)
        total[matrix[row+val][col+val]]--;

        for(int i=val+1;i<=200;i++)
        {
            if(total[i]>=1) return false;
        }
        return true;
        
    }

    int countLocalMaximums(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        if(n==1 && m==1) return min(matrix[0][0],1);
        vector<vector<vector<int>>> prefix(
            n, vector<vector<int>>(m, vector<int>(201, 0))
        );

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int val = matrix[i][j];
                prefix[i][j][val]++;

                for(int k = 0; k <= 200; k++)
                {
                    if(i > 0)
                        prefix[i][j][k] += prefix[i-1][j][k];

                    if(j > 0)
                        prefix[i][j][k] += prefix[i][j-1][k];

                    if(i > 0 && j > 0)
                        prefix[i][j][k] -= prefix[i-1][j-1][k];
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]!=0)
                {
                    if(check(i,j,matrix,prefix))
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};