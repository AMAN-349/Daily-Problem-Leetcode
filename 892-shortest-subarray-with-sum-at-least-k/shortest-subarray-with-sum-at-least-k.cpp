class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        //here we required the priority queue as value can be negative

        deque<pair<long long,int>> dq;
        int n=nums.size();
        int ans=INT_MAX;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=(1LL*nums[i]);
            if(sum>=k)
            {
                ans=min(ans,i+1);
            }
            while(!dq.empty() && sum-dq.front().first>=k)
            {
                ans=min(ans,i-dq.front().second);
                dq.pop_front();
            }
            if(dq.empty())
            {
                dq.push_back({sum,i});
            }
            while(!dq.empty() && dq.back().first>=sum)
            {
                dq.pop_back();
            }
            dq.push_back({sum,i});
        }
        return ans==INT_MAX?-1:ans;
    }
};