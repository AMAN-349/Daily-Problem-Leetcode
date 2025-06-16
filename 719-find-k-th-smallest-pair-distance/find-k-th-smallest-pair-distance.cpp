class Solution {
public:

int countPairs(int mid, const vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    int left = 0;
    for (int right = 0; right < n; ++right) {
        while (nums[right] - nums[left] > mid) {
            ++left;
        }
        count += right - left;
    }
    return count;
}


    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int low = 0;
    int high = nums.back() - nums[0]; 
    int answer = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int cnt = countPairs(mid, nums);
        if (cnt >= k) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return answer;

    }
};