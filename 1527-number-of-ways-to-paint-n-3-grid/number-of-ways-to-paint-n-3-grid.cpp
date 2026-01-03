class Solution {
public:
    vector<vector<int>> v;
    int m;
    int dp[50001][3][3][3];
    static const int mod = 1e9 + 7;

    bool isvalid(const vector<int>& a, const vector<int>& b) {
        for(int i=0;i<3;i++)
            if(a[i] == b[i]) return false;
        return true;
    }

    int find(int r, const vector<int>& temp) {
        if(r == m) return 1;

        int &res = dp[r][temp[0]][temp[1]][temp[2]];
        if(res != -1) return res;

        res = 0;
        for(auto &row : v) {
            if(isvalid(temp, row)) {
                res = (res + find(r+1, row)) % mod;
            }
        }
        return res;
    }

    int numOfWays(int n) {
        m = n;
        memset(dp, -1, sizeof(dp));
        v.clear();
        for(int a=0;a<3;a++)
            for(int b=0;b<3;b++)
                for(int c=0;c<3;c++)
                    if(a!=b && b!=c)
                        v.push_back({a,b,c});

        int ans = 0;
        for(auto &row : v) {
            ans = (ans + find(1, row)) % mod;
        }
        return ans;
    }
};
