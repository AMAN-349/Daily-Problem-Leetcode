class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        stack<long long> s; 
        s.push(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            long long curr = nums[i];

            while (!s.empty()) {
                long long topi = s.top();
                long long g = __gcd(curr, topi);

                if (g > 1) {
                    curr = (curr / g) * topi;
                    s.pop();
                } else {
                    break;
                }
            }
            s.push(curr);
        }

        while (!s.empty()) {
            ans.push_back((int)s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
