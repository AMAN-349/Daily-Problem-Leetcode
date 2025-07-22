class Solution {
public:

    int calsum(int i,int j,vector<int>& nums)
    {
        int sum=0;
        sum=accumulate(nums.begin()+i,nums.begin()+j+1,sum);
        return sum;
    }

    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int> m;
        int i=0,j=0,ans=0;
        int n=nums.size();
        while(j<n)
        {
            int temp=nums[j];
            m[temp]++;
            while (m[nums[j]] > 1) {
                m[nums[i]]--; 
                i++;
            }
            ans=max(ans,calsum(i,j,nums));
            j++;
        }
        return ans;
    }
};