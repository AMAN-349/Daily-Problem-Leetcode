class Solution {
public:

    double gain(int p,int t)
    {
        return (double)(p + 1) / (t + 1) - (double)p / t;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {        
        priority_queue<pair<double, pair<int,int>>> pq;
        for (auto i : classes) {
            pq.push({gain(i[0], i[1]), {i[0], i[1]}});
        }
        while (extraStudents--) {
            auto tmp = pq.top();
            pq.pop();
            int pass = tmp.second.first + 1;
            int total = tmp.second.second + 1;
            pq.push({gain(pass, total), {pass, total}});
        }
        double ans = 0;
        while (!pq.empty()) {
            auto [g, pt] = pq.top(); 
            pq.pop();
            ans += (double)pt.first / pt.second;
        }
        return ans / classes.size();
    }
};
