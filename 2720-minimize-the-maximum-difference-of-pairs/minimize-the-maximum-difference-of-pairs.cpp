class Solution {
public:

    bool isvalid(int m,vector<int>& nums,int p)
    {
        int cnt=0;
        for(int i=1;i<nums.size();i++)
        {
            if((nums[i]-nums[i-1])<=m)
            {
                cnt++;
                i++;
            }
        }
        return cnt>=p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int mini=INT_MAX;
        for(int i=1;i<nums.size();i++)
        {
            mini=min(mini,nums[i]-nums[i-1]);
        }
        int maxi=nums[nums.size()-1]-nums[0];
        int l=mini;
        int r=maxi;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(isvalid(m,nums,p))
            {
                if(!isvalid(m-1,nums,p))
                {
                    return m;
                }
                else{
                    r=m-1;
                }
            }
            else{
                l=m+1;
            }
        }
        return 0;
    }
};