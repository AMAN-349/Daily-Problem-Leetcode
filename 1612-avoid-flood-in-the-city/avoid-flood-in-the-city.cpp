class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> full; 
        set<int> dryDays;             
        vector<int> ans(n, 1);   
        
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                dryDays.insert(i); 
            } else {
                int lake = rains[i];
                ans[i] = -1;
                
                if (full.find(lake) != full.end()) {
                    auto it = dryDays.upper_bound(full[lake]);
                    if (it == dryDays.end()) {
                        return {}; 
                    }
                    ans[*it] = lake; 
                    dryDays.erase(it);
                }
                full[lake] = i; 
            }
        }
        return ans;
    }
};
