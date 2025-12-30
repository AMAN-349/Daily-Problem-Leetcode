class Solution {
public:

    bool ischeck(int i1,int i2,int j1,int j2,vector<vector<int>>& grid)
    {
        set<int> s2;
        int temp=0;
        set<int> s1;
        for(int i=i1;i<=i2;i++)
        {
            int temp=0;
            for(int j=j1;j<=j2;j++)
            {
                temp+=grid[i][j];
                s2.insert(grid[i][j]);
            }
            s1.insert(temp);
        }
        for(int j=j1;j<=j2;j++)
        {
            int temp=0;
            for(int i=i1;i<=i2;i++)
            {
                temp+=grid[i][j];
                s2.insert(grid[i][j]);
            }
            s1.insert(temp);
        }
        int i=i1;
        int j=j1;
        temp=0;
        while(i<=i2 && j<=j2)
        {
            temp+=grid[i][j];
            i++;
            j++;
        }
        s1.insert(temp);
        i=i1;
        j=j2;
        temp=0;
        while(i<=i2 && j>=j1)
        {
            temp+=grid[i][j];
            i++;
            j--;
        }
        s1.insert(temp); 
        return s1.size() == 1 &&
        s2.size() == 9 &&
        *s2.begin() == 1 &&
        *prev(s2.end()) == 9;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=2;i<n;i++)
        {
            for(int j=2;j<m;j++)
            {
                if(ischeck(i-2,i,j-2,j,grid))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};