class Solution {
public:
    int maxProduct(int n) {
        string s=to_string(n);
        cout<<s[0];
        sort(s.begin(),s.end());

        return (s[s.size()-1]-'0')*(s[s.size()-2]-'0');
    }
};