#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        set<int> s; 
        long long currentSum = 0, maxSum = 0;
        int n = nums.size();
        int i = 0, j = 0;

        while (i < n) {
            while (i < n && s.find(nums[i]) == s.end() && s.size() < k) {
                s.insert(nums[i]);
                currentSum += nums[i];
                i++;
            }

            if (s.size() == k) {
                maxSum = max(maxSum, currentSum);
            }

            s.erase(nums[j]);
            currentSum -= nums[j];
            j++;
        }

        return maxSum;
    }
};
