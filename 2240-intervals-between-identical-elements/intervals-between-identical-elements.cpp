class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, pair<long,long>> m;
        vector<long long> result(n);
        for(int i = 0; i < n; ++i) {
            auto [count, val] = m[arr[i]];
            if(count == 0) {
                m[arr[i]] = {1, i};
                continue;
            }
            result[i] = i * count - val;
            m[arr[i]].second += i;
            ++m[arr[i]].first;
        }
        
        m.clear();
        for(int i = n - 1; i >= 0; --i) {
            auto [count, val] = m[arr[i]];
            if(count == 0) {
                m[arr[i]] = {1, i};
                continue;
            }
            result[i] += val - i * count;
            m[arr[i]].second += i;
            ++m[arr[i]].first;
        }
        return result;
    }
};