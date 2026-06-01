class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        sort(cost.begin(),cost.end());
        int ans=0;
        int cnt=0;
        for(int i=n-1;i>=0;i--)
        {
            ans+=cost[i];
            cnt++;
            if(cnt==2)
            {
                i--;
                cnt=0;
            }
        }
        return ans;
    }
};