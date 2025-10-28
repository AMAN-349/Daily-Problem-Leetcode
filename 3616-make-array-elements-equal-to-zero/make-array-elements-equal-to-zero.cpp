class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        vector<int> zeroes;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                zeroes.push_back(i);
            }
        }
        for(auto i:zeroes)
        {
            int lsum=accumulate(nums.begin(), nums.begin()+i+1, 0);
            int rsum=accumulate(nums.begin()+i, nums.end(), 0);
            if(lsum==rsum)
            {
                ans+=2;
            }
            else if(abs(lsum-rsum)==1)
            {
                ans+=1;
            }
        }
        return ans;
    }
};