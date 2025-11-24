class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        vector<bool> ans;
        long long temp=0;
        for(int i=0;i<n;i++)
        {
            temp=temp*2+nums[i];
            if(temp%5==0)
            {
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
            temp=temp%5;
        }
        return ans;
    }
};