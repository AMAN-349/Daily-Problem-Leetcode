class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> prevsmaller(n);
        vector<int> nextsmaller(n);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                nextsmaller[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            nextsmaller[st.top()]=n;
            st.pop();
        }

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                prevsmaller[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            prevsmaller[st.top()]=-1;
            st.pop();
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,(nextsmaller[i]-prevsmaller[i]-1)*heights[i]);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> heights(m,0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) 
            {
                if (matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }
};