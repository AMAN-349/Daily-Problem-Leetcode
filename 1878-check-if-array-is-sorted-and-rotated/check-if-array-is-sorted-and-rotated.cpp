class Solution {
public:

    bool ifsorted(int start,int end,vector<int>& nums)
    {
        for(int i=start+1;i<end;i++)
        {
            if(nums[i-1]>nums[i])
            {
                return false;
            }
        }
        return true;
    }

    bool check(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return true;
        int ind=-1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
            {
                ind=i;
                break;
            }
        }
        if(ind==-1) return true;
        bool ans=(ifsorted(0,ind,nums) && ifsorted(ind,n,nums));
        if(ans==false) return false;

        vector<int> v1(nums.begin(),nums.begin()+ind);
        vector<int> v2(nums.begin()+ind,nums.end());

        for(auto i:v1)
        {
            v2.push_back(i);
        }
        for(int i=1;i<n;i++)
        {
            if(v2[i-1]>v2[i]) return false;
        }
        return true;
    }
};