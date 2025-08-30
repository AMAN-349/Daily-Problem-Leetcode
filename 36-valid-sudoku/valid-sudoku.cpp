class Solution {
public:
    bool isrow(vector<vector<char>>board,int row)
    {
        int n=board.size();
        set<char> s;
        for(int i=0;i<9;i++)
        {
            if(s.find(board[row][i])!=s.end())
            {
                return false;
            }
            if(board[row][i]!='.')
            {
                s.insert(board[row][i]);
            }
        }
        return true;
    }
    bool iscol(vector<vector<char>>board,int col)
    {
        set<char> s;
        for(int i=0;i<9;i++)
        {
            if(s.find(board[i][col])!=s.end())
            {
                return false;
            }
            if(board[i][col]!='.')
            {
                s.insert(board[i][col]);
            }
        }
        return true;
        
    }
    bool isbox(vector<vector<char>>board,int startrow,int startcol)
    {
        set<char> s;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                char curr = board[i + startrow][j + startcol];
                if(s.find(curr)!=s.end())
                {
                    return false;
                }
                if(curr!='.')
                {
                    s.insert(board[startrow+i][startcol+j]);
                }
            }
        }
        return true;
    }
    bool isvalid(vector<vector<char>>board,int r,int c)
    {
        int srow=r-(r%3);
        int scol=c-(c%3);
        return isrow(board,r) && iscol(board,c) && isbox(board,srow,scol);
    }
    
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(!isvalid(board,i,j))
                {
                    return false;
                }
            }
        }
        return true;
    }
};