class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }

    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), cmp);

        vector<int> count(n, 0);
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > busy;

        priority_queue<int, vector<int>, greater<int>> freeRooms;

        for (int i = 0; i < n; i++)
            freeRooms.push(i);

        for (auto &m : meetings) {
            long long start = m[0];
            long long end = m[1];
            long long duration = end - start;

            while (!busy.empty() && busy.top().first <= start) {
                freeRooms.push(busy.top().second);
                busy.pop();
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();
                count[room]++;
                busy.push({end, room});
            } else {
                auto [freeTime, room] = busy.top();
                busy.pop();
                count[room]++;
                busy.push({freeTime + duration, room});
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[ans])
                ans = i;
        }
        return ans;
    }
};
