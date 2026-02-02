class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int jump=0;
        for(int i=0;i<n-1;i++)
        {
            jump=max(jump,i+nums[i]);
            if(jump==i) return false;
        }
        return true;
    }
};