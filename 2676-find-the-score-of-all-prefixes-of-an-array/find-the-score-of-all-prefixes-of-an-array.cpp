typedef long long ll;
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& v) {
        vector<ll> ans;
        ll mx = 0LL, s = 0LL;
        for(int x : v) {
            mx = max(mx,(ll)x);
            s += (x + mx);
            ans.push_back(s);
        }
        return ans;
    }
};