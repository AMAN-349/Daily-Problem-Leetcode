class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        string ans;
        map<char,int> m;
        for(auto i:s)
        {
            m[i]++;
        }
        char temp='#';
        if(s.size()%2!=0)
        {
            int mid=n/2;
            temp=s[mid];
            m[temp]--;
            if(m[temp]==0)
            {
                m.erase(temp);
            }
        }
        int left=(n/2)-1;
        for(auto i:m)
        {
            int cnt=i.second/2;
            while(cnt--)
            {
                ans+=i.first;
            }
        }
        string ans2=ans;
        reverse(ans.begin(),ans.end());
        if(temp=='#')
        {
            return ans2+ans;
        }
        return ans2+temp+ans;
    }
};