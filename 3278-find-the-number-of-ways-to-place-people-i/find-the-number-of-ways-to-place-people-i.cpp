class Solution {
public:

    bool static cmp(vector<int> v1, vector<int> v2)
    {
        if(v1[1]==v2[1])
        {
            return v1[0]<v2[0];
        }
        return v1[1]>v2[1];
    }


    int find(vector<vector<int>>& points, int px1, int py1, int px2, int py2)
    {
        int cnt=0;
        for(auto i:points)
        {
            if(i[0]>=px1 && i[0]<=px2 && i[1]>=py2 && i[1]<=py1)
            {
                cnt++;
            }
        }
        return cnt;
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        sort(points.begin(),points.end(),cmp);
        for(auto i:points)
        {
            cout<<i[0]<<i[1];
            cout<<" ";
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int temp=find(points,points[i][0],points[i][1],points[j][0],points[j][1]);
                cout<<temp;
                if(temp==2)
                {
                    ans++;
                }
            }
        }
        return ans;

    }
};