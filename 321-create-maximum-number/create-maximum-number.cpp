class Solution {
public:
    vector<int> pickMax(const vector<int>& v, int len) {
        int n = v.size();
        vector<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && v[i] > st.back() && 
                   (st.size() - 1) + (n - i) >= len) {
                st.pop_back();
            }
            if (st.size() < len) st.push_back(v[i]);
        }
        return st;
    }

    vector<int> merge(vector<int> a, vector<int> b) {
        vector<int> res;
        while (!a.empty() || !b.empty()) {
            if (a > b) {
                res.push_back(a[0]);
                a.erase(a.begin());
            } else {
                res.push_back(b[0]);
                b.erase(b.begin());
            }
        }
        return res;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> best;

        for (int i = max(0, k - (int)nums2.size()); 
             i <= min(k, (int)nums1.size()); i++) 
        {
            vector<int> p1 = pickMax(nums1, i);
            vector<int> p2 = pickMax(nums2, k - i);
            vector<int> candidate = merge(p1, p2);

            if (best.empty() || candidate > best)
                best = candidate;
        }
        return best;
    }
};
