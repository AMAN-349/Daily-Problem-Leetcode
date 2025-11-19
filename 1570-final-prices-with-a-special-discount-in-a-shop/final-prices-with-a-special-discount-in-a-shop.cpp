class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        stack<int> s;
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && prices[i]<=prices[s.top()])
            {
                ans[s.top()]=prices[s.top()]-prices[i];
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
        {
            ans[s.top()]=prices[s.top()];
            s.pop();
        }
        return ans;
    }
};