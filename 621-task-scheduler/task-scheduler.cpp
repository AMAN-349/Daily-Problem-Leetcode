class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
        for(auto i:tasks)
        {
            m[i]++;
        }
        priority_queue<int> pq;
        for(auto i:m)
        {
            pq.push(i.second);
        }
        int cnt=0;
        while(!pq.empty())
        {
            vector<int> prev;
            for(int i=0;i<=n;i++)
            {
                if(!pq.empty())
                {
                    int temp=pq.top();
                    pq.pop();
                    if((temp-1)>0)
                    {
                        prev.push_back(temp-1);
                    }
                    cnt++;
                }
                else if(prev.size()>0){
                    cnt++;
                }
            }
            for(auto i:prev)
            {
                pq.push(i);
            }
        }
        return cnt;
    }
};