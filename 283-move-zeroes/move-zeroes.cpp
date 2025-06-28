class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int cnt=0;
        while(i<nums.size())
        {
            if(nums[i]!=0)
            {
                if(i!=cnt)
                {
                    swap(nums[i],nums[cnt]);
                }
                cnt++;
            }
            i++;
        }
    }
};