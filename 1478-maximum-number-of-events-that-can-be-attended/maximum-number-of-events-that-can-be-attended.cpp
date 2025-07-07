class Solution {
public:

    bool static cmp(vector<int> v1,vector<int> v2)
    {
        if(v1[0]==v2[0])
        {
            return v1[1]<v2[1];
        }
        return v1[0]<v2[0];
    }

    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),cmp);
        int ans=0;
        int count=0;
        int i=0,n=events.size();
        int day=1;
        priority_queue<int, vector<int>, greater<int>> pq;
        while(i<n || !pq.empty())
        {
            while(i<n && events[i][0]==day)
            {
                pq.push(events[i][1]);
                i++;
            }
            while(!pq.empty() && pq.top() < day)
            {
                pq.pop();
            }
            if(!pq.empty())
            {
                ans++;
                pq.pop();
            }
            day++;
        }
        return ans;
    }
};