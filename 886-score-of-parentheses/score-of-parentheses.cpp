class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<string> st;

        for(auto i:s)
        {
            if(i=='(')
            {
                st.push(string(1,i));
            }
            else{
                int cnt=0;
                while(st.top() != "(")
                {
                    cnt += stoi(st.top());
                    st.pop();
                }
                st.pop();
                if(cnt==0)
                {
                    st.push(to_string(1));
                }
                else{
                    st.push(to_string(2*cnt));
                }
            }
        }
        int ans=0;

        while(!st.empty())
        {
            ans+=stoi(st.top());
            st.pop();
        }

        return ans;
    }
};