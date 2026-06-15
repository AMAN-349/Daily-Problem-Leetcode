class Solution {
public:
    static int getKey(const vector<int>& v) {
        if (v.size() == 1)
            return v[0];         

        vector<int> temp = v; 
        nth_element(temp.begin(), temp.begin() + 1, temp.end());
        return temp[1];
    }

    static bool cmp(const vector<int>& v1, const vector<int>& v2) {
        return getKey(v1) > getKey(v2);
    }

    int secondmin(vector<int>& v)
    {
        nth_element(v.begin(), v.begin() + 1, v.end());
        return v[1];
    }

    long long maxRatings(vector<vector<int>>& units) {
        sort(units.begin(), units.end(), cmp);

        int n = units.size();
        long long sum = 0;
        int mini = INT_MAX;

        for (int i = 0; i < n - 1; i++)
        {
            if (units[i].size() == 1)
            {
                sum += units[i][0];
                mini = min(mini, units[i][0]);
            }
            else
            {
                sum += secondmin(units[i]);
                mini = min(mini, *min_element(units[i].begin(), units[i].end()));
            }
        }
        cout<<sum<<" ";

        mini = min(mini,
                   *min_element(units[n - 1].begin(), units[n - 1].end()));

        sum += mini;
        return sum;
    }
};