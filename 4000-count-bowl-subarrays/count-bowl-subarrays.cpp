class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> nge(n);
        vector<int> pge(n);
        stack<int> s;
        for(int i=1;i<nums.size();i++)
        {
            while(!s.empty() && nums[i]>nums[s.top()])
            {
                nge[s.top()]=nums[i];
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
        {
            nge[s.top()]=-1;
            s.pop();
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && nums[i]>nums[s.top()])
            {
                pge[s.top()]=nums[i];
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
        {
            pge[s.top()]=-1;
            s.pop();
        }
        long long ans=0;
        for(int i=1;i<n-1;i++)
        {
            if(nge[i]!=-1 && pge[i]!=-1)
            {
                ans++;
            }
        }
        return ans;
    }
};