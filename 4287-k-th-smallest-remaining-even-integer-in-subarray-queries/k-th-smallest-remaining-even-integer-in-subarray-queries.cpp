class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> clesimvora = queries; 
        vector<int> ans;
    
        vector<int> evenIdx;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2 == 0) evenIdx.push_back(i);
        }

        for(auto& q : clesimvora) {
            int l = q[0], r = q[1], k = q[2];

            long long low = 1, high = 20000000000; 
            long long res = high;

            while(low <= high) {
                long long mid = low + (high - low) / 2;
                if (mid % 2 != 0) mid--;
                
                auto it_start = lower_bound(evenIdx.begin(), evenIdx.end(), l);
                auto it_end = upper_bound(evenIdx.begin(), evenIdx.end(), r);
                
                int countInRange = 0;
                if (it_start < it_end) {
                    auto it_val = upper_bound(it_start, it_end, mid, [&](int val, int idx) {
                        return val < nums[idx];
                    });
                    countInRange = distance(it_start, it_val);
                }

                if ((mid / 2) - countInRange >= k) {
                    res = mid;
                    high = mid - 2;
                } else {
                    low = mid + 2;
                }
            }
            ans.push_back((int)res);
        }
        return ans;
    }
};