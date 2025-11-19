class Solution {
public:
    int findFinalValue(vector<int>& nums, int target) {
        set<int> s(nums.begin(),nums.end());
        while(true)
        {
            if(s.find(target)==s.end())
            {
                return target;
            }
            target*=2;
        }
        return -1;
    }
};