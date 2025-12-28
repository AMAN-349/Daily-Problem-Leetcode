class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k%2==0 || k%5==0)
        {
            return -1;
        }
        int cnt=2;
        int curr=11;
        while(true)
        {
            int rem=curr%k;
            if(rem==0)
            {
                return cnt;
            }
            curr=rem*10+1;
            cnt++;
        }
        return cnt;
    }
};