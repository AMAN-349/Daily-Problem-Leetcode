class Solution {
public:
    bool find(int n) {
        if (n <= 1)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    vector<int> prime(int n) {
        vector<int> temp;
        for (int i = 2; i < n; i++) {
            if (find(i)) {
                temp.push_back(i);
            }
        }
        return temp;
    }

    bool primeSubOperation(vector<int>& nums) {
        int prev = -1;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> primes = prime(nums[i]);
            bool found = false;

            for (int j = primes.size()-1; j >=0; j--) {
                int modified_value = nums[i] - primes[j];
                if (modified_value > prev) {
                    prev = modified_value;
                    found = true;
                    res.push_back(prev);
                    break;
                }
            }

            if (!found) {
                res.push_back(nums[i]);
                prev=nums[i];
            }
        }
        for(int i=1;i<res.size();i++)
        {
            if(res[i]<=res[i-1])
            {
                return false;
            }
        }
        return true;
    }
};
