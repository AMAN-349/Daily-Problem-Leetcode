class Solution {
public:
    
    int maxFreeTime(int eventTime,vector<int>& startTime,vector<int>& endTime) {
        const int n = startTime.size();
        if (n == 0) return eventTime;              

        vector<int> gaps;
        gaps.reserve(n + 1);
        for (int i = 0; i <= n; ++i) {
            if (i == 0)
                gaps.push_back(startTime[0]);                   
            else if (i == n)
                gaps.push_back(eventTime - endTime[n - 1]);     
            else
                gaps.push_back(startTime[i] - endTime[i - 1]);  
        }

        vector<int> prefix(n + 1), suffix(n + 1);
        prefix[0] = gaps[0];
        for (int i = 1; i <= n; ++i)
            prefix[i] = max(prefix[i - 1], gaps[i]);

        suffix[n] = gaps[n];
        for (int i = n - 1; i >= 0; --i)
            suffix[i] = max(suffix[i + 1], gaps[i]);

        int answer = 0;
        for (int i = 0; i < n; ++i) {
            int length   = endTime[i] - startTime[i];
            int adjacent = gaps[i] + gaps[i + 1];

            int leftMax  = (i > 0)      ? prefix[i - 1] : 0;
            int rightMax = (i + 2 <= n) ? suffix[i + 2] : 0;

            bool canMove = (leftMax >= length || rightMax >= length);

            int candidate = adjacent + (canMove ? length : 0);
            answer = max(answer, candidate);
        }
        return answer;
    }
};
