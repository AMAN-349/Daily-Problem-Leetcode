class Solution {
public:
    int find(const string& s) {
        stack<char> st;
        int count = 0;

        for (char ch : s) {
            if (ch == '(') {
                st.push(ch);
            }
            else if (ch == ')') {
                if (!st.empty() && st.top() == '(')
                    st.pop();
                else
                    count++;
            }
        }

        return count + st.size();
    }

    void ans(const string& s, int mini,
             unordered_set<string>& res,
             unordered_set<string>& visited) {

        if (visited.count(s))
            return;

        visited.insert(s);

        if (mini == 0) {
            if (find(s) == 0)
                res.insert(s);
            return;
        }

        for (int i = 0; i < s.size(); i++) {

            // Only remove parentheses
            if (s[i] != '(' && s[i] != ')')
                continue;

            string next = s.substr(0, i) + s.substr(i + 1);

            ans(next, mini - 1, res, visited);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int mini = find(s);

        unordered_set<string> res;
        unordered_set<string> visited;

        ans(s, mini, res, visited);

        return vector<string>(res.begin(), res.end());
    }
};