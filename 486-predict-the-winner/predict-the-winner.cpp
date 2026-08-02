class Solution {
public:
    int find(int i, int j, bool turn, vector<int>& nums) {
        if (i > j)
            return 0;

        if (turn) {
            return max(
                nums[i] + find(i + 1, j, false, nums),
                nums[j] + find(i, j - 1, false, nums)
            );
        } else {
            return min(
                find(i + 1, j, true, nums),
                find(i, j - 1, true, nums)
            );
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int alice = find(0, nums.size() - 1, true, nums);
        int bob = total - alice;
        return alice >= bob;
    }
};