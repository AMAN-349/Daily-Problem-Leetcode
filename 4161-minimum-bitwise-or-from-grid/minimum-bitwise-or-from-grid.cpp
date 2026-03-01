class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        int mx = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                mx = max(mx, grid[i][j]);

        int temp = log2(mx)+1;
        cout<<temp;
        int ans = 0;
        bool flag=false;
        int extra=0;
        for (int i = temp - 1; i >= 0; i--) {
            int curr=extra|(1<<i);
            flag=true;
            for (int j = 0; j < n; j++) {
                int cnt = 0;
                for (int k = 0; k < m; k++) {
                    if ((grid[j][k]) & curr)
                        cnt++;
                }
                if (cnt == m) {
                    ans |= (1LL << i);
                    cout<<ans<<" ";
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                extra=curr;
            }
        }

        return ans;
    }
};