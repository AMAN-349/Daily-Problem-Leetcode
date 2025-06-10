class Solution {
public:
    int maxDifference(string s) {
        map<char,int> m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        int odd=INT_MIN;
        int even=INT_MAX;
        for(auto i:m)
        {
            if(i.second>0 && i.second%2==0)
            {
                even=min(even,i.second);
            }
            else{
                odd=max(odd,i.second);
            }
        }
        return odd-even;
    }
};