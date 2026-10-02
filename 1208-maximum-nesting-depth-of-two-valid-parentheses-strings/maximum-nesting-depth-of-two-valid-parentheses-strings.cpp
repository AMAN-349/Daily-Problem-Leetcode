class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        int d=0;
        vector<int> ans;
        for(auto i:seq)
        {
            if(i=='(')
            {
                ++d;
                ans.push_back(d % 2);
            }
            else{
                ans.push_back(d % 2);
                d--;
            }
        }
        return ans;
    }
};