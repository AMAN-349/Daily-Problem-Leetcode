class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> v(1,poured);
        int cnt=0;
        while(cnt!=query_row)
        {
            int temp=v.size();
            vector<double> nextrow(temp+1,0);
            for(int i=0;i<temp;i++)
            {
                if(v[i]>1.0)
                {
                    double rem=(double)(v[i]-1)/2.0;
                    nextrow[i]+=rem;
                    nextrow[i+1]+=rem;
                }
            }
            v=nextrow;
            cnt++;
        }
        return min(1.0, v[query_glass]);
    }
};