class Solution {
public:
    
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<long long> ans;
        vector<long long>suff(n,0);
        vector<long long>pref(n,0);
        vector<long long>arr(n,0);
        arr[0]=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>=nums[i-1])
            {
                arr[i]=arr[i-1]+1;
            }
            else{
                arr[i]=1;
            }
        }
        pref[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            pref[i]=pref[i-1]+arr[i];
        }
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<=nums[i+1])
            {
                suff[i]=suff[i+1]+1;
            }
        }
        for(auto q:queries)
        {
            int l=q[0];
            int r=q[1];
            if(l==0)
            {
                ans.push_back(pref[r]);
            }
            else{
                int idx=suff[l-1]+l-1;
                long long sum=pref[r]-pref[l-1];
                int mini=min(r,idx)-l+1;
                sum-=(mini*arr[l-1]);
                ans.push_back(sum);
            }
        }
        return ans;
        
    }
};