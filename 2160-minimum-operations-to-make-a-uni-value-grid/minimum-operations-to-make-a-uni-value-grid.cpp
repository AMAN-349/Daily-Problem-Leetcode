class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();
        int m=grid[0].size();

        int cnto=0;
        int cnte=0;
        vector<int> v;

        for(auto i:grid)
        {
            for(auto j:i)
            {
                if(j%2==0)
                {
                    cnte++;
                }
                else{
                    cnto++;
                }
                v.push_back(j);
            }
        }
        sort(v.begin(),v.end());
        if(x%2==0 && (cnte>0 && cnto>0))
        {
            return -1;
        }
        n=v.size();
        int mid=n/2;
        int elem=v[mid];
        int ans=0;
        for(auto i:v)
        {
            if(abs(elem-i)%x==0)
            {
                ans+=(abs((elem-i))/x);
            }
            else{
                return -1;
            }
        }
        return ans;
    }
};