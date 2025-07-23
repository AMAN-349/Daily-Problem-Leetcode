class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        string flag1 = (x > y) ? "ab" : "ba";
        string flag2 = (flag1 == "ab") ? "ba" : "ab";

        char ch1 = flag1[0];
        char ch2 = flag1[1];
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (!st.empty() && st.top() == ch1 && s[i] == ch2) {
                ans += max(x, y);
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        string temp = "";
        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());

        ch1 = flag2[0];
        ch2 = flag2[1];
        for (int i = 0; i < temp.size(); i++) {
            if (!st.empty() && st.top() == ch1 && temp[i] == ch2) {
                ans += min(x, y);
                st.pop();
            } else {
                st.push(temp[i]);
            }
        }

        return ans;
    }
};