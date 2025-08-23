class Solution {
public:

    int minimumArea(int sr, int er, int sc, int ec, vector<vector<int>>& grid) {
        int top = er+1, bottom = sr-1, left = ec+1, right = sc-1;
        for(int i = sr; i <= er; i++) {
            for(int j = sc; j <= ec; j++) {
                if(grid[i][j] == 1) {
                    top = min(top, i);
                    bottom = max(bottom, i);
                    left = min(left, j);
                    right = max(right, j);
                }
            }
        }
        if(top > bottom || left > right) return 0;
        return (bottom-top+1)*(right-left+1);
    }

    int verticalBreak(int sr,int er,int sc,int ec,vector<vector<int>>& grid) {
        int res = INT_MAX;
        for(int temp1 = sr; temp1 < er; temp1++) {
            int a1 = minimumArea(sr, temp1, sc, ec, grid);
            int a2 = minimumArea(temp1+1, er, sc, ec, grid); 
            res = min(res, a1+a2);
        }
        return res == INT_MAX ? 0 : res;
    }

    int horizontalBreak(int sr,int er,int sc,int ec,vector<vector<int>>& grid) {
        int res = INT_MAX;
        for(int temp1 = sc; temp1 < ec; temp1++) {
            int a1 = minimumArea(sr, er, sc, temp1, grid);
            int a2 = minimumArea(sr, er, temp1+1, ec, grid);
            res = min(res, a1 + a2);
        }
        return res == INT_MAX ? 0 : res;
    }


    int minimumSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int res=INT_MAX;

        //for first case
        for(int i=0;i<n-2;i++)
        {
            int a1=minimumArea(0,i,0,m-1,grid);
            int a2=horizontalBreak(i+1,n-1,0,m-1,grid);
            res=min(res,a1+a2);
        }
        //cout<<"First"<<res;

        //for second case
        for(int i=n-1;i>1;i--)
        {
            int a1=minimumArea(i,n-1,0,m-1,grid);
            int a2=horizontalBreak(0,i-1,0,m-1,grid);
            res=min(res,a1+a2);
        }
        //cout<<"Second"<<res<<" ";

        //for third case
        for(int i=0;i<n-2;i++)
        {
            int a1=minimumArea(0,i,0,m-1,grid);
            cout<<"Third Sum"<<a1<<" ";
            int a2=verticalBreak(i+1,n-1,0,m-1,grid);
            cout<<"vertical break"<<a2<<" ";
            res=min(res,a1+a2);
        }
        cout<<"Third"<<res;

        //for fourth case
        for(int i=0;i<m-2;i++)
        {
            int a1=minimumArea(0,n-1,0,i,grid);
            int a2=verticalBreak(0,n-1,i+1,m-1,grid);
            res=min(res,a1+a2);
        }
        //cout<<"Fourth"<<res;

        //for fifth case
        for(int i=m-1;i>1;i--)
        {
            int a1=minimumArea(0,n-1,i,m-1,grid);
            int a2=verticalBreak(0,n-1,0,i-1,grid);
            res=min(res,a1+a2);
        }
        //cout<<"Fifth"<<res;

        //for sixth case
        for(int i=0;i<m-2;i++)
        {
            int a1=minimumArea(0,n-1,0,i,grid);
            int a2=horizontalBreak(0,n-1,i+1,m-1,grid);
            res=min(res,a1+a2);
        }
        //cout<<"Sixth"<<res;

        if(res==INT_MAX)
        {
            for(int i=0;i<n-1;i++)
            {
                int a1=minimumArea(0,i,0,m-1,grid);
                int a2=minimumArea(i+1,n-1,0,m-1,grid);
                res=min(res,a1+a2);
            }
            for(int i=0;i<m-1;i++)
            {
                int a1=minimumArea(0,n-1,0,i,grid);
                int a2=minimumArea(0,n-1,i+1,m-1,grid);
                res=min(res,a1+a2);
            }
        }

        return res;


    }
};