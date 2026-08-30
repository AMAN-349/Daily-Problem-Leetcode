class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        auto maxi=max_element(nums.begin(),nums.end());
        auto mini=min_element(nums.begin(),nums.end());

        int diffstart1=maxi-nums.begin()+1;
        int diffstart2=mini-nums.begin()+1;

        int diffend1=nums.end()-maxi;
        int diffend2=nums.end()-mini;

        int ans=INT_MAX;

        ans=min(ans,max(diffstart1,diffstart2));
        ans=min(ans,max(diffend1,diffend2));

        ans=min(ans,diffstart1+diffend2);
        ans=min(ans,diffstart2+diffend1);

        return ans;

    }
};