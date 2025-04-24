class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        set<int> all(nums.begin(), nums.end());     
        int totalUnique = all.size();

        unordered_map<int, int> freq;
        int l = 0, r = 0;
        int ans = 0;
        int currUnique = 0;

        while (r < n) {
            freq[nums[r]]++;
            if (freq[nums[r]] == 1) currUnique++;

            while (currUnique == totalUnique) {
                ans += n - r;
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) currUnique--;
                l++;
            }
            r++;
        }
        return ans;
    }
};
