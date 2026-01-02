class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        int len=n/2;
        unordered_map<int,int> m;
        for(auto i:nums)
        {
            m[i]++;
        }
        for(auto i:m)
        {
            if(i.second==len)
            {
                return i.first;
            }
        }
        return -1;
    }
};