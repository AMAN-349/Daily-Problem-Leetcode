class Solution {
public: 
    int find(string s)
    {
        int n=s.size();
        long long temp=0;
        for(int i=n-1;i>=0;i--)
        {
            if (s[i] == '1')
            {
                temp |= (1LL << i);
            }
        }
        return temp;
    }

    bool hasAllCodes(string s, int k) {
        int n=s.size();
        set<int> st;
        string temp=s.substr(0,k);
        st.insert(find(temp));
        for(int i=1;i<n;i++)
        {
            temp.erase(temp.begin());
            temp+=s[i];
            st.insert(find(temp));
        }
        int expected=pow(2,k);
        return st.size()==expected;

    }
};