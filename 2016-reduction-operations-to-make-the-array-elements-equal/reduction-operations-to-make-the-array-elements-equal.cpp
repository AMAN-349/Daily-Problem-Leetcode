class Solution {
public:

    struct cmp {
        bool operator()(const int &a, const int &b) const {
            return a > b;
        }
    };

    int reductionOperations(vector<int>& nums) {
        int cnt = 0;
        map<int,int,cmp> m;

        for (int x : nums) m[x]++;

        if (!m.empty()) {
            auto last = prev(m.end());
            for (auto it = m.begin(); it != last; ++it) {
                auto nxt = next(it);
                cnt += it->second;
                cout<<cnt<<" ";
                nxt->second += it->second;
            }
        }
        return cnt;
    }
};
