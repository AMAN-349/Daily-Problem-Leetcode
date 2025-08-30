class Solution {
public:
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
    
    bool dfs(int i, int j, int pi, int pj, int n, int m, 
             vector<vector<char>>& grid, vector<vector<bool>>& visited) 
    {
        visited[i][j] = true;
        
        for(auto d : dir) {
            int x = i + d.first;
            int y = j + d.second;
            
            if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == grid[i][j]) {
                if(!visited[x][y]) {
                    if(dfs(x, y, i, j, n, m, grid, visited)) 
                        return true;
                } 
                else if(x != pi || y != pj) { 
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j]) {
                    if(dfs(i, j, -1, -1, n, m, grid, visited))
                        return true;
                }
            }
        }
        return false;
    }
};
