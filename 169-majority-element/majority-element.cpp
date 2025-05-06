class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //moore's voting algorithm
        int n=nums.size();
        int cnt=0;
        int ans;
        for(int i=0;i<n;i++)
        {
            if(cnt==0)
            {
                ans=nums[i];
                cnt++;
            }
            else if(nums[i]==ans)
            {
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return ans;

    }
};