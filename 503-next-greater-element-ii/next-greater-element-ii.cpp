class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<2*n;i++)
        {
            int idx = i % n;
            while(!st.empty() && nums[st.top()]<nums[idx])
            {
                ans[st.top()]=nums[idx];
                st.pop();
            }
            if(i<n)
            {
                st.push(idx);
            }
        }
        while(!st.empty())
        {
            ans[st.top()]=-1;
            st.pop();
        }
        return ans;
    }
};