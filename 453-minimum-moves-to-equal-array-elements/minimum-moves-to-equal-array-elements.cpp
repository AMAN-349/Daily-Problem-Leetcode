class Solution {
public:
    int minMoves(vector<int>& nums) {
        int total = 0;
        int mini = *min_element(nums.begin(), nums.end());
        for (int num : nums) {
            total += num;
        }
        return total - mini * nums.size();
    }
};
