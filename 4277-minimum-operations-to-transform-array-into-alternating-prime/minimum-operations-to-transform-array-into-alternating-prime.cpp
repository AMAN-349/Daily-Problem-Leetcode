class Solution {
public:
    const int MAXN = 100007;
    vector<bool> isPrime;
    vector<int> primes;
    vector<int> nonprimes;

    Solution() {
        sieve();
    }

    void sieve() {
        isPrime.assign(MAXN + 1, true);
        isPrime[0] = isPrime[1] = false;

        for(int i = 2; i * i <= MAXN; i++) {
            if(isPrime[i]) {
                for(int j = i * i; j <= MAXN; j += i)
                    isPrime[j] = false;
            }
        }

        for(int i = 2; i <= MAXN; i++) {
            if(isPrime[i]) primes.push_back(i);
            else{
                nonprimes.push_back(i);
            }
        }
    }

    int minOperations(vector<int>& nums) {
        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(i % 2 == 0 && !isPrime[nums[i]]) {
                auto it = upper_bound(primes.begin(), primes.end(), nums[i]);
                if(it == primes.end()) continue;
                int temp=abs(nums[i] - *it);
                ans += temp;
            }
            else if(i % 2 == 1 && isPrime[nums[i]]) {
                int x = nums[i] + 1;

                while(isPrime[x]) x++;

                ans += (x - nums[i]);
            }
        }

        return ans;
    }
};