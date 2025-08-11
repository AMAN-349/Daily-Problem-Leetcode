class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int mod = 1e9 + 7;
        vector<int> powers;
    
        for (int bit = 0; n > 0; bit++) {
            if (n & 1) {
                powers.push_back(1 << bit); 
            }
            n >>= 1;
        }
        
        vector<int> ans;
        for (auto &q : queries) {
            int i = q[0];
            int j = q[1];
            long long prod = 1;  
            
            for (int k = i; k <= j; k++) {
                prod = (prod * powers[k]) % mod;
            }
            ans.push_back((int)prod);
        }
        return ans;
    }
};
