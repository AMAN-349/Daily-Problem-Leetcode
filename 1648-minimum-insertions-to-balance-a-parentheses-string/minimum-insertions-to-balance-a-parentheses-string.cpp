class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        stack<char> st;
        int ans=0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else{
                if(i+1<n && s[i+1]==')')
                {
                    if(st.empty())
                    {
                        ans++;
                    }
                    else{
                        st.pop();
                    }
                    i++;
                }
                else{
                    if(!st.empty())
                    {
                        st.pop();
                        ans++;
                    }
                    else{
                        ans+=2;
                    }
                }
            }
        }
        while(!st.empty())
        {
            ans+=2;
            st.pop();
        }
        return ans;
    }
};