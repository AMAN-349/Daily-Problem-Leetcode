class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> v;  

        for (int i = 0; i < n; i++) {
            double t = (double)(target - position[i]) / speed[i];
            v.push_back({position[i], t});
        }

        sort(v.begin(), v.end());  

        int cnt = 0;
        double time = 0.0;

        for (int i = n - 1; i >= 0; i--) {
            if (v[i].second > time) {
                cnt++;
                time = v[i].second;
            }
        }

        return cnt;
    }
};
