class Solution {
public:

    class cmp {
        public:
            bool operator()(pair<long long,long long>& a, pair<long long,long long>& b) {
                if (a.first == b.first)
                    return a.second > b.second;

                return a.first > b.first;
            }
        };

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,cmp> pq1;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,cmp> pq2;

        vector<int> ans;

        int n=tasks.size();

        for(int i=0;i<servers.size();i++)
        {
            pq1.push({servers[i],i});
        }

        long long currtime=0;

        for(int t=0;t<n;t++)
        {
            currtime = max(currtime, 1LL*t);
            while(!pq2.empty() && currtime>=pq2.top().first)
            {
                pq1.push({servers[pq2.top().second],pq2.top().second});
                pq2.pop();
            }
            if(pq1.empty())
            {
                while(currtime<pq2.top().first)
                {
                    currtime++;
                }

                while(!pq2.empty() && currtime>=pq2.top().first)
                {
                    pq1.push({servers[pq2.top().second],pq2.top().second});
                    pq2.pop();
                }
            }
            auto temp = pq1.top();
            pq1.pop();
            int idx = temp.second;
            ans.push_back(idx);
            pq2.push({1LL*currtime + tasks[t], idx});
        }

        return ans;

    }
};