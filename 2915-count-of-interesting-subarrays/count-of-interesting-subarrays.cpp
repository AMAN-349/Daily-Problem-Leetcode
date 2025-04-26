class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        long long ans = 0;
        int sum = 0;
        map<int,int> m;
        m[0] = 1;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] % modulo == k)
                sum += 1;
            int rem = sum % modulo;
            int need = (rem - k + modulo) % modulo; 
            ans += m[need];
            m[rem]++;
        }
        
        return ans;
    }
};
