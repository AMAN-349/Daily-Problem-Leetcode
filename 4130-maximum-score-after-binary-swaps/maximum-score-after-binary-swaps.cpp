class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        int n=nums.size();
        int cnt=0;
        int ind=-1;
        priority_queue<int> pq;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
            if(s[i]=='1' && !pq.empty())
            {
                ans+=pq.top();
                pq.pop();
            }
        }
        return ans;

    }
};