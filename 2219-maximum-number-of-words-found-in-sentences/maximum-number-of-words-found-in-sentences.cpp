class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans=0;
        for(auto i:sentences)
        {
            int cnt=count(i.begin(),i.end(),' ');
            ans=max(ans,cnt+1);
        }
        return ans;
    }
};