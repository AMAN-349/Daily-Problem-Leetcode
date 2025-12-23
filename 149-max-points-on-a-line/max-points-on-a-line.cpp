class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            map<float,int> m;
            for(int j=0;j<n;j++)
            {
                if(j!=i)
                {
                    int dy,dx;
                    if(j>i)
                    {
                        dy=points[j][1]-points[i][1];
                        dx=points[j][0]-points[i][0];
                    }
                    else{
                        dy=points[i][1]-points[j][1];
                        dx=points[i][0]-points[j][0];
                    }
                    if(dx==0) 
                    {
                        m[-350]++;
                        continue;
                    }
                    float slope=(float)dy/dx;
                    m[slope]++;
                }
            }
            int ans=0;
            for(auto i:m)
            {
                ans=max(ans,i.second);
            }
            res=max(res,ans+1);
            m.clear();
        }
        return res;
    }
};