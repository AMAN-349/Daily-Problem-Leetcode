class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n=bottomLeft.size();
        int m=topRight.size();
        long long ans=0;
        long long res=0;
        for(int i=0;i<n;i++)
        {
            int x1=bottomLeft[i][0];
            int y1=bottomLeft[i][1];
            int x2=topRight[i][0];
            int y2=topRight[i][1];
            for(int j=i+1;j<m;j++)
            {
                int nx1=bottomLeft[j][0];
                int ny1=bottomLeft[j][1];
                int nx2=topRight[j][0];
                int ny2=topRight[j][1];

                if(nx1>=x2 || x1>=nx2 || ny2<=y1 || ny1>=y2)
                {
                    continue;
                }
                int x_overlap=min(nx2,x2)-max(nx1,x1);
                int y_overlap=min(ny2,y2)-max(ny1,y1);

                ans=min(x_overlap,y_overlap);
                res=max(res,1LL*ans*ans);
            }
        }
        return res;
    }
};