class Solution {
public:

    int binsearch(int l,int r,vector<int>& nums,int target)
    {
        while(l<=r)
        {
            int m=(l+r)/2;
            if(nums[m]==target)
            {
                return m;
            }
            else if(nums[m]>target)
            {
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int ind=0;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(nums[m]<=nums[n-1])
            {
                r=m-1;
            }
            else{
                if(nums[m]>nums[m+1])
                {
                    ind=m;
                    break;
                }
                else{
                    l=m+1;
                }
            }
        }
        cout<<ind<<" ";
        int ans1=binsearch(0,ind,nums,target); 
        int ans2=binsearch(ind+1,n-1,nums,target);
        if(ans1!=-1)
        {
            return ans1;
        }
        return ans2;
    }
};