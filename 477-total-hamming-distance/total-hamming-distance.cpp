class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        int bitmask = 1; 

        while (bitmask) { 
            int cnt1 = 0;
 
            for (int i = 0; i < n; ++i) {
                if (nums[i] & bitmask) {
                    cnt1++;
                }
            }

            int cnt0 = n - cnt1;
            total += cnt0 * cnt1;  
            
            bitmask <<= 1;  
        }

        return total;
    }
};
