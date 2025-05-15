class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<words.size();i++)
        {
            if(groups[i]!=groups[i-1])
            {
                ans.push_back(i);
            }
        }
        vector<string> res;
        for(int i=0;i<ans.size();i++)
        {
            res.push_back(words[ans[i]]);
        }
        return res;
    }
};