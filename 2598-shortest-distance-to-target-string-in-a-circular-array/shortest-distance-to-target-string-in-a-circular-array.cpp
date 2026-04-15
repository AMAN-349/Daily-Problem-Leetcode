class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        vector<int> v;
        for(int i=0;i<words.size();i++)
        {
            if(words[i]==target)
            {
                v.push_back(i);
            }
        }
        if(v.empty()) return -1;
        int ans=INT_MAX;
        for(auto i:v)
        {
            ans=min(ans,abs(i-startIndex));
            ans=min(ans,(i+n-startIndex));
            ans=min(ans,(n-i+startIndex));
        }
        return ans;

    }
};