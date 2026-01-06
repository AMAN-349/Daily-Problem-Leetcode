class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_set<int> s(nums.begin(),nums.end());
        for(auto i:s)
        {
            int temp=i;
            int cnt=1;
            if(!s.count(i-1))
            {
                while(s.find(++temp)!=s.end())
                {
                    cnt++;
                }
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};