class Solution {
public:

    static bool cmp(pair<int,int> p1,pair<int,int> p2)
    {
        return p1.second<p2.second;
    }

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        sort(v.begin(),v.begin()+k,cmp);
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};