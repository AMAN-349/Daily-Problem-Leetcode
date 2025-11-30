class Solution {
public:
    int maxDistinct(string s) {
        int n=s.size();
        set<int> st(s.begin(),s.end());
        return st.size();
    }
};