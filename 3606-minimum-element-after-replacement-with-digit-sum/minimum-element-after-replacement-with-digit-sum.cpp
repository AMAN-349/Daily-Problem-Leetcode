class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(auto i:nums)
        {
            string temp=to_string(i);
            int res=0;
            for(auto j:temp)
            {
                res+=(j-'0');
            }
            ans=min(ans,res);
        }
        return ans;
    }
};