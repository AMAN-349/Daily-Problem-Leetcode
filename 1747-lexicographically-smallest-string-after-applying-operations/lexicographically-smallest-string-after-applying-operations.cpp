class Solution {
public:

    void isadd(string& s, int a)
    {
        for(int i=0;i<s.size();i++)
        {
            if(i%2!=0)
            {
                int sum=(s[i]-'0')+a;
                sum=sum%10;
                s[i]=(sum+'0');
            }
        }
    }

    void isrot(string& s,int b)
    {
        int n=s.size();
        b%=n;
        reverse(s.begin(),s.end()-b);
        reverse(s.end()-b,s.end());
        reverse(s.begin(),s.end());
    }

    string findLexSmallestString(string s, int a, int b) {
        string ans=s;
        queue<string> q;
        unordered_set<string> st;
        q.push(s);
        st.insert(s);
        while(!q.empty())
        {
            string temp=q.front();
            q.pop();
            ans=min(ans,temp);

            string added=temp;
            isadd(added,a);
            if(!st.count(added))
            {
                q.push(added);
                st.insert(added);
            }

            string rotated=temp;
            isrot(rotated,b);
            if(!st.count(rotated))
            {
                q.push(rotated);
                st.insert(rotated);
            }
            
        }
        return ans;
    }
};