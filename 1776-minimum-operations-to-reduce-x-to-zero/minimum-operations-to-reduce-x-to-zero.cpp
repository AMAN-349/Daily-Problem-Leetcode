class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(x>sum) return -1;
        int req=sum-x;
        vector<int> v=nums;
        int ans=INT_MAX;

        int i=0;
        int j=0;
        sum=0;
        while(j<n)
        {
            sum+=v[j];
            while(sum>req && i<=j)
            {
                sum-=v[i];
                i++;
            }
            if(sum==req)
            {
                ans=min(ans,n-(j-i+1));
            }
            j++;
        }
        return ans==INT_MAX?-1:ans;
    }
};