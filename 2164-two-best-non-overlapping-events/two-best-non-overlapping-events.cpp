class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(), cmp);
        vector<int> suffix(n);
        suffix[n-1]=events[n-1][2];
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=max(events[i][2],suffix[i+1]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int endTime = events[i][1];

            int next = lower_bound(
                events.begin() + i + 1,
                events.end(),
                endTime,
                [](const vector<int>& e, int value) {
                    return e[0] <= value;
                }
            )-events.begin();

            int temp = 0;
            if(next<n)
            {
                temp=suffix[next];
            }

            ans = max(ans, events[i][2] + temp);
        }
        return ans;
    }
};
