class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int, int> m;
        for (auto& i : items) {
            m[i[0]] = max(m[i[0]], i[1]);
        }
        
        int max_beauty = 0;
        for (auto& [price, beauty] : m) {
            max_beauty = max(max_beauty, beauty);
            m[price] = max_beauty;
        }

        int maxi=0;
        vector<int> ans;
        for (auto q : queries) {
            auto it = m.upper_bound(q);
            if (it == m.begin()) {
                ans.push_back(0);
            } else {
                --it;
                ans.push_back(it->second);
            }
        }
        return ans;
    }
};