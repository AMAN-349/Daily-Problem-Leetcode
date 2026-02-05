class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> result=nums;
        if(n==1) return result;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                result[i]=0;
            }
            else{
                int temp=i+nums[i];
                temp=(temp%n);
                if(temp>=0)
                {
                    result[i]=nums[temp];
                }
                else
                {   
                    int rem2=n+temp;
                    result[i]=nums[rem2];
                }
            }
        }
        return result;
    }
};