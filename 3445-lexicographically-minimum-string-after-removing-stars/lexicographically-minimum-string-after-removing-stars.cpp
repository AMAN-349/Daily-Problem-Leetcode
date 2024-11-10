class Solution {
public:
    string clearStars(string s) {
        vector<char> vec(s.begin(),s.end());
        vector<stack<int>> temp(26);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='*')
            {
                for(int j=0;j<26;j++)
                {
                    if(!temp[j].empty())
                    {
                        int index=temp[j].top();
                        temp[j].pop();
                        vec[index]='*';
                        break;
                    }
                }
            }
            else{
                temp[s[i]-'a'].push(i);
            }
        }
        string ans="";
        for(auto i:vec)
        {
            if(i!='*')
            {
                ans+=i;
            }
        }
        return ans;
    }
};