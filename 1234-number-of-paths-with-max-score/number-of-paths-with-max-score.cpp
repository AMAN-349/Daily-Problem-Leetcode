class Solution {
public:

    int res;
    int cnt;
    int n,m;
    long long mod=1e9+7;

    int dp[101][101];
    int dp2[101][101][2000];

    bool isValid(int x,int y)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }

    int find(int i, int j, vector<vector<char>>& temp)
    {
        if(i == 0 && j == 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MIN;

        int dx[3] = {-1,-1,0};
        int dy[3] = {0,-1,-1};

        for(int k=0;k<3;k++)
        {
            int nx = i + dx[k];
            int ny = j + dy[k];

            if(isValid(nx,ny) && temp[nx][ny] != 'X')
            {
                int prev = find(nx, ny, temp);

                if(prev != INT_MIN)
                {
                    ans = max(ans, prev + (temp[i][j]-'0'));
                }
            }
        }

        return dp[i][j] = ans;
    }

    int find2(int i,int j,vector<vector<char>>& temp,int sum)
    {
        if(i==0 && j==0)
        {
            if(sum==0)
            {
                return 1;
            }
            return 0;
        }
        if(sum<0) return 0;
        if(dp2[i][j][sum]!=-1)
        {
            return dp2[i][j][sum];
        }
        int ans=0;

        int dx[3]={-1,-1,0};
        int dy[3]={0,-1,-1};

        for(int k=0;k<3;k++)
        {
            int newx=i+dx[k];
            int newy=j+dy[k];

            if(isValid(newx,newy))
            {
                if(temp[newx][newy] == 'X'){
                    continue;
                }
                ans=(ans+find2(newx,newy,temp,sum - (temp[i][j] - '0')))%mod;
            }
        }
        return dp2[i][j][sum]=ans%mod;
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        n=board.size();
        m=board[0].size();
        memset(dp,-1,sizeof(dp));
        memset(dp2,-1,sizeof(dp2));
        vector<vector<char>> temp;
        res=0;
        cnt=0;
        board[0][0]='0';
        board[n-1][m-1]='0';

        for(auto i:board)
        {
            vector<char> v;
            for(auto j:i)
            {
                v.push_back(j);
            }
            temp.push_back(v);
        }
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int ansi=find(n-1, m-1, temp);
        if(ansi==INT_MIN)
        {
            return {0,0};
        }
        int anso=find2(n-1, m-1, temp, ansi%mod);
        return vector<int>({ansi,anso});
    }
};