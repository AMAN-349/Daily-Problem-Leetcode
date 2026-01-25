class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MAX;
        sort(nums.begin(),nums.end());
        if(n==1) return 0;
        deque<int> dq;
        vector<int> mini;
        vector<int> maxi;

        for(int i=0;i<n;i++)
        {
            if(!dq.empty() && dq.front()<=i-k)
            {
                dq.pop_front();
            }
            while(!dq.empty() && nums[i]>=nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1)
            maxi.push_back(nums[dq.front()]);
        }
        while(!dq.empty())
        {
            dq.pop_front();
        }

        for(int i=0;i<n;i++)
        {
            if(!dq.empty() && dq.front()<=i-k)
            {
                dq.pop_front();
            }
            while(!dq.empty() && nums[i]<=nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1)
            mini.push_back(nums[dq.front()]);
        }

        for(int i=0;i<maxi.size();i++)
        {
            ans=min(ans,maxi[i]-mini[i]);
        }

        return ans;
        
    }
};