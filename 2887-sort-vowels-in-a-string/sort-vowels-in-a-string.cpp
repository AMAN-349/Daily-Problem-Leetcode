class Solution {
public:

    bool check(char s)
    {
        if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u' || s=='A' || s=='E' || s=='I' || s=='O' || s=='U')
        {
            return true;
        }
        return false;
    }

    string sortVowels(string s) {
        vector<int> v;
        for(auto i:s)
        {
            if(check(i))
            {
                v.push_back(i-'A');
            }
        }
        sort(v.begin(),v.end());
        int pt=0;
        for(int i=0;i<s.size();i++)
        {
            if(check(s[i]))
            {
                s[i]=char(v[pt]+'A');
                pt++;
            }
        }
        return s;
        
    }
}; 