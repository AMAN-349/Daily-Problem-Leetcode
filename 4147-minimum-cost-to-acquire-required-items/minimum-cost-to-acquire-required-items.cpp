class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long mini=min(costBoth,cost1+cost2);
        long long ans=0;
        ans+=1LL*(mini*1LL*(min(need1,need2)));
        long long min2=min(need1,need2);
        need1-=min2;
        need2-=min2;
        if(need1>0)
        {
            ans+=1LL*min(1LL*need1*cost1,1LL*need1*costBoth);
        }
        else if(need2>0){
            ans+=1LL*min(1LL*need2*cost2,1LL*need2*costBoth);
        }
        return ans;
    }
};