class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char,int> m;
        vector<int> present(26,0);
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]--;
            if(present[s[i]-'a'])
            {
                continue;
            }
            while(!st.empty() && m[st.top()]>0 && s[i]<st.top())
            {
                present[st.top()-'a']=0;
                st.pop();
            }
            st.push(s[i]);
            present[s[i]-'a']=1;
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};