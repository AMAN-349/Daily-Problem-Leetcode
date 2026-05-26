class Solution {
public:
    int numberOfSpecialChars(string temp) {
        unordered_map<char,int> m;
        for(auto i:temp)
        {
            m[i]++;
        }
        int cnt=0;
        for(auto i:temp)
        {
            char l=tolower(i);
            char u=toupper(i);
            if(m.count(l) && m.count(u)) 
            {
                m.erase(l);
                m.erase(u);
                cnt++;
            }
        }
        return cnt;
    }
};