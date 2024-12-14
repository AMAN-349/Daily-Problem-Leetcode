class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int left = 0, right = 0;
        long long count = 0;  // Total count of valid subarrays

        // Min and max heaps storing indices, sorted by nums[index] values
        priority_queue<int, vector<int>, function<bool(int, int)>> minHeap(
            [&nums](int a, int b) { return nums[a] > nums[b]; });
        priority_queue<int, vector<int>, function<bool(int, int)>> maxHeap(
            [&nums](int a, int b) { return nums[a] < nums[b]; });

        while (right < nums.size()) {
            // Add current index to both heaps
            minHeap.push(right);
            maxHeap.push(right);

            // While window violates |nums[i] - nums[j]| ≤ 2 condition
            // Shrink window from left and remove outdated indices
            while (left < right &&
                   nums[maxHeap.top()] - nums[minHeap.top()] > 2) {
                left++;

                // Remove indices that are now outside window
                while (!maxHeap.empty() && maxHeap.top() < left) {
                    maxHeap.pop();
                }
                while (!minHeap.empty() && minHeap.top() < left) {
                    minHeap.pop();
                }
            }

            // Add count of all valid subarrays ending at right
            count += right - left + 1;
            right++;
        }

        return count;
    }
};