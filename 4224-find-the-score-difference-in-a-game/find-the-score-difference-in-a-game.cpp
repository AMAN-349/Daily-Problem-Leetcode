class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int cnt1=0;
        int cnt2=0;
        int curr=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2!=0)
            {
                curr=(curr+1)%2;
            }
            if((i%6)==5)
            {
                curr=(curr+1)%2;
            }
            if(curr==0)
            {
                cnt1+=nums[i];
            }
            else{
                cnt2+=nums[i];
            }
            cout<<cnt1<<" ";
        }
        return cnt1-cnt2;
    }
};