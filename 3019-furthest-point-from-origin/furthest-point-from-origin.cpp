class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cnt1=0;
        int cnt2=0;
        int n=moves.size();
        for(auto i:moves)
        {
            if(i=='L')
            {
                cnt1++;
            }
            else if(i=='R')
            {
                cnt2++;
            }
        }
        return abs(cnt1-cnt2)+(n-(cnt1+cnt2));
    }
};