class Solution {
public:
    int n, m;

    bool isValid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    bool find(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {

        cout<<i<<" "<<j;
        cout<<endl;

        if (i == n-1 && j == m-1) return true;

        vis[i][j] = 1;

        bool ans = false;

        if (grid[i][j] == 1) {
            if (isValid(i, j+1) && !vis[i][j+1] &&
                (grid[i][j+1]==1 || grid[i][j+1]==3 || grid[i][j+1]==5))
                ans |= find(i, j+1, grid, vis);

            if (isValid(i, j-1) && !vis[i][j-1] &&
                (grid[i][j-1]==1 || grid[i][j-1]==4 || grid[i][j-1]==6))
                ans |= find(i, j-1, grid, vis);
        }

        else if (grid[i][j] == 2) {
            if (isValid(i+1, j) && !vis[i+1][j] &&
                (grid[i+1][j]==2 || grid[i+1][j]==5 || grid[i+1][j]==6))
                ans |= find(i+1, j, grid, vis);

            if (isValid(i-1, j) && !vis[i-1][j] &&
                (grid[i-1][j]==2 || grid[i-1][j]==4 || grid[i-1][j]==3))
                ans |= find(i-1, j, grid, vis);
        }

        else if (grid[i][j] == 3) {
            if (isValid(i+1, j) && !vis[i+1][j] &&
                (grid[i+1][j]==2 || grid[i+1][j]==5 || grid[i+1][j]==6))
                ans |= find(i+1, j, grid, vis);

            if (isValid(i, j-1) && !vis[i][j-1] &&
                (grid[i][j-1]==1 || grid[i][j-1]==4 || grid[i][j-1]==6))
                ans |= find(i, j-1, grid, vis);
        }

        else if (grid[i][j] == 4) {
            if (isValid(i+1, j) && !vis[i+1][j] &&
                (grid[i+1][j]==2 || grid[i+1][j]==5 || grid[i+1][j]==6))
                ans |= find(i+1, j, grid, vis);

            if (isValid(i, j+1) && !vis[i][j+1] &&
                (grid[i][j+1]==1 || grid[i][j+1]==3 || grid[i][j+1]==5))
                ans |= find(i, j+1, grid, vis);
        }

        else if (grid[i][j] == 5) {
            if (isValid(i-1, j) && !vis[i-1][j] &&
                (grid[i-1][j]==2 || grid[i-1][j]==3 || grid[i-1][j]==4))
                ans |= find(i-1, j, grid, vis);

            if (isValid(i, j-1) && !vis[i][j-1] &&
                (grid[i][j-1]==1 || grid[i][j-1]==4 || grid[i][j-1]==6))
                ans |= find(i, j-1, grid, vis);
        }

        else { 
            if (isValid(i-1, j) && !vis[i-1][j] &&
                (grid[i-1][j]==2 || grid[i-1][j]==3 || grid[i-1][j]==4))
                ans |= find(i-1, j, grid, vis);

            if (isValid(i, j+1) && !vis[i][j+1] &&
                (grid[i][j+1]==1 || grid[i][j+1]==3 || grid[i][j+1]==5))
                ans |= find(i, j+1, grid, vis);
        }

        return ans;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        return find(0, 0, grid, vis);
    }
};