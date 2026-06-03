class Solution {
public:
    int n;

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n=items.size();
        unordered_map<int,int> freq;
        int maxi = 0;

        for(int i=0;i<n;i++)
        {
            freq[items[i][0]]++;
            maxi = max(maxi, items[i][0]);
        }

        unordered_map<int,int> temp;

        for(auto &[fct, cnt] : freq)
        {
            for(int x = fct; x <= maxi; x += fct)
            {
                temp[fct] += freq[x];
            }

            temp[fct]--; // remove itself
        }

        unordered_map<int,int> m;

        for(int i=0;i<n;i++)
        {
            int fct = items[i][0];
            m[i] = temp[fct];
        }

        priority_queue<pair<float,int>,vector<pair<float,int>>,greater<pair<float,int>>> pq;

        for(int i=0;i<n;i++)
        {
            int fc = items[i][0];
            float pr = items[i][1];
            if(m[i]>=1)
            {
                pr/=(1.0*2);
            }
            pq.push({pr,i});
        }
        int ans=0;

        while(!pq.empty())
        {
            auto [pr, ind] = pq.top();

            int price = items[ind][1];

            if(price > budget)
            {
                pq.pop();
                continue;
            }

            if(m[ind] > 0)
            {
                int k = min(m[ind], budget / price);
                ans += 2 * k;
                budget -= k * price;
                m[ind] -= k;

                if(m[ind] == 0)
                {
                    pq.pop();
                    pq.push({price, ind});
                }
            }
            else
            {
                int k = budget / price;
                ans += k;
                budget -= k * price;
                break;
            }
        }
        return ans;
    }
};