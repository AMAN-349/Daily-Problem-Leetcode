class Solution {
public:

    int n=0;
    int m=0;
    int totalToVisit=0;
    bool issafe(int i,int j)
    {
        return (i>=0 && i<n && j>=0 && j<m);
    }

    int find(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& visited,int count)
    {
        if (grid[i][j] == 2) {
            return (count == totalToVisit) ? 1 : 0;
        }

        visited[i][j]=true;
        int sum=0;
        if(issafe(i,j+1) && !visited[i][j+1] && (grid[i][j+1]!=-1))
        {
            sum+=find(i,j+1,grid,visited,count+1);
        }
        if(issafe(i,j-1) && !visited[i][j-1] && (grid[i][j-1]!=-1))
        {
            sum+=find(i,j-1,grid,visited,count+1);
        }
        if(issafe(i+1,j) && !visited[i+1][j] && (grid[i+1][j]!=-1))
        {
            sum+=find(i+1,j,grid,visited,count+1);
        }
        if(issafe(i-1,j) && !visited[i-1][j] && (grid[i-1][j]!=-1))
        {
            sum+=find(i-1,j,grid,visited,count+1);
        }
        visited[i][j]=false;
        return sum;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int start_i=0;
        int start_j=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != -1) {
                    totalToVisit++;
                }
                if (grid[i][j] == 1) {
                    start_i = i;
                    start_j = j;
                }
            }
        }
        return find(start_i, start_j, grid, visited, 1);
        return 0;
    }
};