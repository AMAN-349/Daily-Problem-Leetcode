class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> m;
        for(auto i:text)
        {
            m[i]++;
        }
        int ans=INT_MAX;
        ans=min(ans,m['b']);
        ans=min(ans,m['a']);
        ans=min(ans,m['l']/2);
        ans=min(ans,m['o']/2);
        ans=min(ans,m['n']);

        return ans;
    }
};