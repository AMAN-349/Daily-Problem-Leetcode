class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        map<char,int> m;
        for(auto i:s)
            {
                m[i]++;
            }
        map<char,int> curr;
        stack<char> st;
        for(int i=0;i<n;i++)
            {
                if(curr[s[i]])
                {
                    m[s[i]]--;
                    continue;
                }
                while(!st.empty() && st.top()>=s[i] && m[st.top()]>1)
                    {
                        m[st.top()]--;
                        curr[st.top()]--;
                        st.pop();
                    }
                    st.push(s[i]);
                    curr[s[i]]++;
            }
        string ans;
        while(!st.empty())
            {
                ans.push_back(st.top());
                st.pop();
            }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};