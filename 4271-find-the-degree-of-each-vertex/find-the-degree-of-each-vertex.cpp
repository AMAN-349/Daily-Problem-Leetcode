class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> ans;
        for(auto i:matrix)
        {
            int sum=accumulate(i.begin(),i.end(),0);
            ans.push_back(sum);
        }
        return ans;
    }
};