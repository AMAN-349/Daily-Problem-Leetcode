class Solution {
public:
    int maxOperations(string nums) {
        int n=nums.size();
        int cnt0=0;
        int cnt1=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]=='1')
            {
                ans+=cnt1;
            }
            while(nums[i]=='1' && i<n)
            {
                cnt1++;
                i++;
            }
            cout<<cnt0<<" "<<cnt1<<" ";
        }
        if(nums[n-1]=='0')
        {
            ans+=cnt1;
        }
        return ans;
    }
};