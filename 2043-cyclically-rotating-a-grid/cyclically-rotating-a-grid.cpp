class Solution {
public:

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        int istart=0;
        int iend=n-1;
        int jstart=0;
        int jend=m-1;
        int temp=1;
        while((iend-istart)>=1 && (jend-jstart)>=1)
        {
            int height = iend - istart + 1;
            int width  = jend - jstart + 1;

            int per = 2 * (height + width) - 4;
            int rem=k%per;
            while(rem--)
            {   
                int temp=grid[istart][jstart];
                for(int k=jstart;k<jend;k++)
                {
                    grid[istart][k]=grid[istart][k+1];
                }

                for(int k=istart;k<iend;k++)
                {
                    grid[k][jend]=grid[k+1][jend];
                }

                for(int k=jend;k>jstart;k--)
                {
                    grid[iend][k]=grid[iend][k-1];
                }

                for(int k=iend;k>istart;k--)
                {
                    grid[k][istart]=grid[k-1][istart];
                }
                grid[istart+1][jstart]=temp;
            }

            istart++;
            iend--;
            jstart++;
            jend--;
        }

        return grid;
    }
};