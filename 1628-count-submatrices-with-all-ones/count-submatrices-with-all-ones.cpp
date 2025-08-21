class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        vector<int> height(m,0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) height[j] = 0;
                else height[j]++;
            }
            ans += countRow(height);
        }

        return ans;
    }

    int countRow(vector<int>& heights)
    {
        int n=heights.size();
        stack<int> st;
        int ans=0;
        vector<int> sum(n, 0);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                int prev=st.top();
                sum[i]=sum[prev] + heights[i]*(i-prev);
            }
            else{
                sum[i]=heights[i]*(i+1);
            }
            st.push(i);
            ans+=sum[i];
        }
        return ans;
    }


};