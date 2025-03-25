class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans=0;
        int temp=0;
        int mask=0;
        for(int i=31;i>=0;i--)
        {
            mask = mask | 1<<i;
            set<int> s;
            for(int i=0;i<nums.size();i++)
            {
                s.insert(nums[i] & mask);
            }
            temp = ans | 1<<i;
            for(auto i:s)
            {
                if(s.contains(temp^i))
                {
                    ans=temp;
                }
            }
        }
        return ans;
    }
};