class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        for(auto i:nums)
        {
            x=x^i;
        }
        return x;
    }
};