class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int,int>> v;
        int n=positions.size();
        for(int i=0;i<positions.size();i++)
        {
            v.push_back({positions[i],i});
        }
        sort(v.begin(),v.end());
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            if(directions[v[i].second]=='R')
            {
                s.push(v[i].second);
            }
            else{
                int curr=healths[v[i].second];
                int cnt=0;
                while(!s.empty() && curr>healths[s.top()])
                {
                    healths[s.top()]=0;
                    s.pop();
                    curr--;
                }
                int idx = v[i].second;
                if(s.empty() && curr > 0)
                {
                    healths[idx] = curr;
                }
                else{
                    if(curr==healths[s.top()])
                    {
                        healths[s.top()]=0;
                        healths[v[i].second]=0;
                        s.pop();
                        continue;
                    }
                    --healths[s.top()];
                    healths[v[i].second]=0;
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            if(healths[i] > 0)
                ans.push_back(healths[i]);
        }
        return ans;
    }
};