class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n=nums.size();
        set<int> s;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            long long val=nums[i];
            auto it=s.lower_bound(val-valueDiff);
            if(it!=s.end() && *it<=val+valueDiff)
            {
                return true;
            }
            s.insert(nums[i]);
            if(i >= indexDiff){
                s.erase(nums[i - indexDiff]);
            }
        }
        return false;
    }
};