class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty=0;
        int ans=0;
        while(true)
        {
            ans+=numBottles;
            empty+=numBottles;
            if(numExchange>empty)
            {
                break;
            }
            else{
                numBottles=1;
                empty-=numExchange;
                numExchange++;
            }
        }
        return ans;
    }
};