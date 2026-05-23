class Solution {
public:

    long long countSubarraysLessThanTarget(vector<int>& arr, int target) {
        int n = arr.size();

        int left = 0;
        long long sum = 0;
        long long count = 0;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            // Shrink window until sum < target
            while (left <= right && sum > target) {
                sum -= arr[left];
                left++;
            }

            // All subarrays ending at right
            // and starting from left to right are valid
            count += (right - left + 1);
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countSubarraysLessThanTarget(nums,goal)-countSubarraysLessThanTarget(nums,goal-1);

    }
};
