class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> s(nums1.begin(), nums1.end());
        int n = nums1.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            auto it = s.upper_bound(nums2[i]);
            if (it == s.end()) {
                it = s.begin();
            }
            ans.push_back(*it);
            s.erase(it);
        }
        return ans;
    }
};
