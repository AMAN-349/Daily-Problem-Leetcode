class Solution {
public:

    struct cmp{
        bool operator()(pair<int,int>&a ,pair<int,int>& b)
        {
            return a.first>b.first;
        }
    };
    
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        int ans=0;
        int n=apples.size();
        int today=1;
        for(int i=0;i<n;i++)
            {
                int exp=days[i]+i;
                int app=apples[i];
                pq.push({exp,app});
                while(!pq.empty() && (pq.top().first<today || pq.top().second==0))
                    {
                        pq.pop();
                    }
                if(!pq.empty())
                {
                    ans++;
                    pair<int,int> temp=pq.top();
                    pq.pop();
                    temp.second--;
                    pq.push(temp);
                }
                today++;
            }
        while(!pq.empty())
            {
                while(!pq.empty() && (pq.top().first<today || pq.top().second==0))
                    {
                        pq.pop();
                    }
                if(!pq.empty())
                {
                    ans++;
                    pair<int,int> temp=pq.top();
                    pq.pop();
                    temp.second--;
                    pq.push(temp);
                }
                today++;
            }
        return ans;
    }
};