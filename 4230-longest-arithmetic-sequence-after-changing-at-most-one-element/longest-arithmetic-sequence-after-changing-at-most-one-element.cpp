class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,1);
        vector<int> suffix(n,1);
        prefix[1]=2;
        suffix[n-2]=2;

        int currdiff=nums[1]-nums[0];

        for(int i=2;i<n;i++)
        {
            if(nums[i]-nums[i-1]==currdiff)
            {
                prefix[i]=prefix[i-1]+1;
            }
            else{
                currdiff=nums[i]-nums[i-1];
                prefix[i]=2;
            }
        }

        currdiff=nums[n-1]-nums[n-2];

        for(int i=n-3;i>=0;i--)
        {
            if(nums[i+1]-nums[i]==currdiff)
            {
                suffix[i]=suffix[i+1]+1;
            }
            else{
                currdiff=nums[i+1]-nums[i];
                suffix[i]=2;
            }
        }

        int ans=*max_element(prefix.begin(),prefix.end());
        ans=*max_element(suffix.begin(),suffix.end());
        if(ans<n)
        {
            ans++;
        }
        for(int i=1;i<n-1;i++)
        {
            float avg=(nums[i-1]+nums[i+1])/2.0;
            float d=avg-nums[i-1];
            float leftd=1e8,rightd=1e8;
            if(i>1)
            {
                leftd=nums[i-1]-nums[i-2];
            }
            if(i<n-2)
            {
                rightd=nums[i+2]-nums[i+1];
            }
            if((leftd==d || leftd==1e8) && (rightd==d || rightd==1e8))
            {
                ans=max(ans,1+prefix[i-1]+suffix[i+1]);
            }
            else if((leftd==d || leftd==1e8))
            {
                ans=max(ans,2+prefix[i-1]);
            }
            else if((rightd==d || rightd==1e8))
            {
                ans=max(ans,2+suffix[i+1]);
            }
            else
            {
                ans=max(ans,prefix[i-1]+1);
                ans=max(ans,suffix[i+1]+1);
                ans=max(ans,3);
            }
        }
        return ans;

    }
};