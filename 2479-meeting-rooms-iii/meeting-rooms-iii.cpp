class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> rooms;
        for (int i = 0; i < n; ++i) rooms.push(i);

        using P = pair<long long,int>;                       
        priority_queue<P, vector<P>, greater<P>> meet;

        vector<long long> cnt(n, 0);                          

        for (auto &mt : meetings) {
            long long start = mt[0], end = mt[1];
            long long dur = end - start;

            while (!meet.empty() && meet.top().first <= start) {
                rooms.push(meet.top().second);
                meet.pop();
            }

            if (!rooms.empty()) {
                int room = rooms.top(); rooms.pop();
                cnt[room]++;                                  
                meet.emplace(end, room);
            } else {
                auto [earliestEnd, room] = meet.top(); 
                meet.pop();
                cnt[room]++;
                meet.emplace(earliestEnd + dur, room);       
            }
        }

        int best = 0;
        for (int i = 1; i < n; ++i)
            if (cnt[i] > cnt[best] ||                        
               (cnt[i] == cnt[best] && i < best))            
                best = i;
        return best;
    }
};
