class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum1=accumulate(gas.begin(),gas.end(),0);
        int sum2=accumulate(cost.begin(),cost.end(),0);
        int n=gas.size();

        if(sum2>sum1)
        {
            return -1;
        }
        int r=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            r+=gas[i]-cost[i];
            if(r<0)
            {
                ans=i+1;
                r=0;
            }
        }
        return ans;
    }
};