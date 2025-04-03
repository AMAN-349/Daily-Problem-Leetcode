class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<long long>pf(nums.size(),0);
        vector<long long>sf(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
            pf[i]=nums[i];
            if(i>0)
            {
                pf[i]=max(pf[i],pf[i-1]);
            }
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            sf[i]=nums[i];
            if(i<nums.size()-1)
            {
                sf[i]=max(sf[i],sf[i+1]);
            }
        }
        long long ans=0;
        for(int i=1;i<nums.size()-1;i++)
        {
            long long t=nums[i];
            ans=max(ans,(pf[i-1]-t)*sf[i+1]);
        }
        return ans;
    }
};