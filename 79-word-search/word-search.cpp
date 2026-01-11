class Solution {
public:
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    int n,m;

    bool isValid(int r,int c)
    {
        return r>=0 && r<n && c>=0 && c<m;
    }

    bool dfs(int i,int j,int n,int m,string word,vector<vector<char>>& board,int k,vector<vector<bool>>& vis)
    {
        if(board[i][j] != word[k])
            return false;
        
        if(k == word.size() - 1)
            return true;

        vis[i][j] = true;

        for(int w=0;w<4;w++)
        {
            int nrow=i+delrow[w];
            int ncol=j+delcol[w];

            if(isValid(nrow,ncol) && !vis[nrow][ncol])
            {
                if(dfs(nrow,ncol,n,m,word,board,k+1,vis))
                {
                    return true;
                }
            }
        }
        vis[i][j]=false;
        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();


        vector<vector<bool>> visited(n, vector<bool>(m, false)); 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(dfs(i,j,n,m,word,board,0,visited))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};