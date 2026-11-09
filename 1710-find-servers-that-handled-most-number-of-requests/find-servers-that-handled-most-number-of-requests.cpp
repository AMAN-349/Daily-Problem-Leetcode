class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        unordered_map<int,int> mp;

        multiset<int> avl;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> uavl;

        int n=arrival.size();
        int currtime=0;

        for(int i=0;i<k;i++)
        {
            avl.insert(i);
        }

        vector<int> ans;

        for(int i=0;i<n;i++)
        {
            int t=arrival[i];
            currtime=max(currtime,t);

            while(!uavl.empty() && uavl.top().first<=currtime)
            {
                avl.insert(uavl.top().second);
                uavl.pop();
            }

            if(avl.empty())
            {
                continue;
            }

            int temp=(i%k);
            auto it=avl.lower_bound(temp);

            if(it == avl.end())
            {
                it=avl.lower_bound(0);
            }

            int ind=*it;
            mp[ind]++;
            avl.erase(it);
            uavl.push({currtime+load[i],ind});
        }

        int temp=0;

        for(auto i:mp)
        {
            temp=max(temp,i.second);
        }

        for(auto i:mp)
        {
            if(i.second==temp)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};