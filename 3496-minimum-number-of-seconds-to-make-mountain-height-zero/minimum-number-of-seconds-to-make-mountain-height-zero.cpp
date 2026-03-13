class Solution {
public:
    
    using ll = long long;

    struct cmp {
        bool operator()(pair<ll,pair<ll,ll>>& a, pair<ll,pair<ll,ll>>& b) {
            return (a.first+a.second.first)>(b.first+b.second.first);
        }
    };


    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n=workerTimes.size();
        priority_queue<pair<ll ,pair<ll,ll>>,
               vector<pair<ll,pair<ll,ll>>>,cmp> pq;

        for(int i = 0; i < n; i++)
        {
            pq.push({workerTimes[i], {0, workerTimes[i]}});
        }

        while(mountainHeight>=1)
        {
            pair<ll,pair<ll,ll>> temp=pq.top();
            vector<pair<ll,pair<ll,ll>>> v;
            v.push_back(temp);
            mountainHeight--;
            pq.pop();
            while(!pq.empty() && pq.top().first==temp.first && mountainHeight>0)
            {
                v.push_back(pq.top());
                pq.pop();
                mountainHeight--;
            }

            for(auto i:v)
            {
                ll p1=i.first;
                ll p2=i.second.first;
                ll p3=i.second.second;

                pq.push({1LL*p1+p3,{1LL*p1+p2,p3}});
            }
        }

        long long ans=0;

        while(!pq.empty())
        {
            pair<int,pair<int,int>> temp=pq.top();
            ans=max(ans,pq.top().second.first);
            pq.pop();
        }

        return ans;

    }
};