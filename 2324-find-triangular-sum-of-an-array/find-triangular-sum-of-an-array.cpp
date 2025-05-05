class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        if (n == 1) {
            return nums[0];
        }
        while (n != 1) {
            temp.clear();
            for (int i = 0; i < n - 1; i++) {
                temp.push_back((nums[i] + nums[i + 1]) % 10);
            }
            nums = temp;
            n--;
        }
        return nums[0];  
    }
};
