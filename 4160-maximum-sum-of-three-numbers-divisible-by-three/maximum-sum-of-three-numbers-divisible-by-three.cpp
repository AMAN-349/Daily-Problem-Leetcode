class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),greater<int>());
        vector<int> v1,v2,v3;
        for(auto i:nums)
        {
            int rem=i%3;
            if(rem==0)
            {
                v1.push_back(i);
            }
            else if(rem==1)
            {
                v2.push_back(i);
            }
            else{
                v3.push_back(i);
            }
        }
        int ans=0;
        if(v1.size()>=3)
        {
            ans=max(ans,v1[0]+v1[1]+v1[2]);
        }
        if(v2.size()>=3)
        {
            ans=max(ans,v2[0]+v2[1]+v2[2]);
        }
        if(v3.size()>=3)
        {
            ans=max(ans,v3[0]+v3[1]+v3[2]);
        }
        if(v1.size()>=1 && v2.size()>=1 && v3.size()>=1)
        {
            ans=max(ans,v1[0]+v2[0]+v3[0]);
        }
        return ans;



    }
};