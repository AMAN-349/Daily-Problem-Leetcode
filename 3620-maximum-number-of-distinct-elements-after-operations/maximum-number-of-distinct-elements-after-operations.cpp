class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<int> used;
        int last = INT_MIN;
        
        for (int x : nums) {
            int candidate = max(x - k, last + 1);
            if (candidate <= x + k) {
                used.insert(candidate);
                last = candidate;
            }
        }

        return used.size();
    }
};
