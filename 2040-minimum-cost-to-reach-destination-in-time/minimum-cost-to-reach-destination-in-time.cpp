class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int,int>>> adj(n); 

        for(auto i:edges)
        {
            int u=i[0], v=i[1], w=i[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }


        vector<vector<int>> dist(n+1, vector<int>(maxTime+1,1e8));
        dist[0][0]=passingFees[0];

        //cost node time
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        pq.push({passingFees[0], {0, 0}});

        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();
            int cost = temp.first;
            int time = temp.second.first;
            int node = temp.second.second;

            if (cost > dist[node][time]) continue;

            for (auto &it : adj[node]) {
                int adjnode = it.first;
                int adjtime = it.second;

                int newTime = time + adjtime;
                if (newTime > maxTime) continue;

                int newCost = cost + passingFees[adjnode];

                if (newCost < dist[adjnode][newTime]) {
                    dist[adjnode][newTime]= newCost;
                    pq.push({newCost, {newTime, adjnode}});
                }
            }
        }
        int ans = INT_MAX;
        for(int t=0; t<=maxTime; t++)
            ans = min(ans, dist[n-1][t]);

        return ans==1e8 ? -1 : ans;

    }
};