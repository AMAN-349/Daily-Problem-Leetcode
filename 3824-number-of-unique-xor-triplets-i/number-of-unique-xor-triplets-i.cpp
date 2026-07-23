class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return 1;
        }
        if(n==2)
        {
            return 2;
        }

        int msb = 0;

        for (int i = 31; i >= 0; i--) {
            if ((n & (1U << i)) != 0) {
                msb = i;
                break;
            }
        }

        return (1U << msb)*2;
    }
};