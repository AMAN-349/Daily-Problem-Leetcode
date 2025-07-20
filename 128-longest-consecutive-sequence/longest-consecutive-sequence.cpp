class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;
        
        for (int num : numSet) {
            // Check if the current number is the start of a sequence
            if (numSet.count(num - 1) == 0) {
                int currentNum = num;
                int currentStreak = 1;
                
                // Find the length of the consecutive sequence
                while (numSet.count(currentNum + 1) > 0) {
                    currentNum++;
                    currentStreak++;
                }
                
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        
        return longestStreak;
    }
};