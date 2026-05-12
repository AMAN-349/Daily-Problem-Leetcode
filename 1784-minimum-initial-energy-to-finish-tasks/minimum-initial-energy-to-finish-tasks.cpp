class Solution {
public:

    static bool cmp(vector<int>& p1,vector<int>& p2)
    {
        return p1[1]-p1[0]>p2[1]-p2[0];
    }

    bool poss(int num,vector<vector<int>>& tasks)
    {
        for(auto i:tasks)
        {
            int act=i[0];
            int req=i[1];

            if(req>num)
            {
                return false;
            }
            if(act>num)
            {
                return false;
            }
            else{
                num-=act;
            }
        }
        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        int n=tasks.size();
        int l=0;
        sort(tasks.begin(),tasks.end(),cmp);
        int r=0;
        for(auto i:tasks)
        {
            l=max(l,i[1]);
            r+=i[1];
        }
        int ans=0;

        while(l<=r)
        {
            int m=(l+r)/2;
            if(poss(m,tasks))
            {
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};