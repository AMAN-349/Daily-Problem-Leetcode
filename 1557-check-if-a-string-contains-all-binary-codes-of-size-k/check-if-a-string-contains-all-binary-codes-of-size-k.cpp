class Solution {
public: 

    bool hasAllCodes(string s, int k) {
        int n=s.size();
        set<string> st;
        string temp=s.substr(0,k);
        st.insert(temp);
        for(int i=1;i<n;i++)
        {
            temp.erase(temp.begin());
            temp+=s[i];
            st.insert(temp);
        }
        int expected=pow(2,k);
        return st.size()==expected;

    }
};