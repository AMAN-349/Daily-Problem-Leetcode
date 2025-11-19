class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && heights[s.top()]>heights[i])
            {
                prefix[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
        {
            prefix[s.top()]=n;
            s.pop();
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && heights[s.top()]>heights[i])
            {
                suffix[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
        {
            suffix[s.top()]=-1;
            s.pop();
        }
        for(auto i:prefix)
        {
            cout<<i<<" ";
        }
        for(auto i:suffix)
        {
            cout<<i<<" ";
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int len=prefix[i]-suffix[i]-1;
            ans=max(ans,len*heights[i]);
        }
        return ans;
    }
};