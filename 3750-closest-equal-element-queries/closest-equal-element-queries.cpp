class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        unordered_map<int,set<int>> m;
        unordered_map<int,int> ans;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]].insert(i);
        }
        vector<int> res;
        for (auto i : queries)
        {
            if (m.find(nums[i]) == m.end())
            {
                res.push_back(-1);
                continue;
            }

            set<int>& s = m[nums[i]];

            if (s.size() == 1)
            {
                res.push_back(-1);
                continue;
            }

            auto it = s.lower_bound(i);

            int temp = INT_MAX;

            auto it2 = next(it);
            if (it2 != s.end())
            {
                temp = min(temp, *it2 - i);
            }
            else
            {
                temp = min(temp, *s.begin() + (n - i));
            }
            if (it != s.begin())
            {
                auto it1 = prev(it);
                temp = min(temp, i - *it1);
            }
            else
            {
                auto last = prev(s.end());
                temp = min(temp, i + (n - *last));
            }
            res.push_back(temp);
        }
        return res;
    }
};