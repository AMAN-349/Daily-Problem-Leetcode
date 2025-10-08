class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //now we do using binary search due to this failed in sp
        int n=nums.size();
        vector<int> temp;
        for(int i=0;i<nums.size();i++)
        {
            if(temp.size()==0)
            {
                temp.push_back(nums[i]);
            }
            else{
                auto lp=lower_bound(temp.begin(),temp.end(),nums[i]);
                if(lp==temp.end())
                {
                    temp.push_back(nums[i]);
                }
                else{
                    temp[lp-temp.begin()]=nums[i];
                }
            }
        }
        return temp.size();
    }
};