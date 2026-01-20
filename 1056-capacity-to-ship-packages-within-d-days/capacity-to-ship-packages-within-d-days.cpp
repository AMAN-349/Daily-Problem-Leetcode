class Solution {
public:

    bool poss(int curr,vector<int>& weights,int days)
    {
        int taken=1;
        int sum=0;
        for(int i=0;i<weights.size();i++)
        {
            if(weights[i]>curr)
            {
                return false;
            }
            sum+=weights[i];
            if(sum>curr)
            {
                sum=0;
                taken++;
                i--;
            }
        }
        return taken<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int l=1;
        int r=accumulate(weights.begin(),weights.end(),0);
        int ans=0;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(poss(m,weights,days))
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