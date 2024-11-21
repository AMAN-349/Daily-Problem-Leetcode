class Solution {
public:

    void find(vector<vector<int>>& temp, int i, int j, int m, int n)
    {
        int temp2;

        // Up
        temp2 = i - 1;
        while (temp2 >= 0 && temp[temp2][j] != 2 && temp[temp2][j] != 1)
        {
            temp[temp2][j] = 3; 
            temp2--;
        }

        // Down
        temp2 = i + 1;
        while (temp2 < m && temp[temp2][j] != 2 && temp[temp2][j] != 1)
        {
            temp[temp2][j] = 3;
            temp2++;
        }

        // Left
        temp2 = j - 1;
        while (temp2 >= 0 && temp[i][temp2] != 2 && temp[i][temp2] != 1)
        {
            temp[i][temp2] = 3; 
            temp2--;
        }

        // Right
        temp2 = j + 1;
        while (temp2 < n && temp[i][temp2] != 2 && temp[i][temp2] != 1)
        {
            temp[i][temp2] = 3; 
            temp2++;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> temp(m, vector<int>(n, 0)); 

        for (auto& guard : guards)
        {
            temp[guard[0]][guard[1]] = 1;
        }
        for (auto& wall : walls)
        {
            temp[wall[0]][wall[1]] = 2;
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (temp[i][j] == 1)
                {
                    find(temp, i, j, m, n);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (temp[i][j] == 0)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};
