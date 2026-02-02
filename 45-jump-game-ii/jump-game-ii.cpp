class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int temp=0;
        int c=0;
        int ans=0;

        for(int i=0;i<n-1;i++)
        {
            temp=max(temp,i+nums[i]);
            if(c==i)
            {
                ans++;
                c=temp;
            }
        }
        return ans;
    }
};