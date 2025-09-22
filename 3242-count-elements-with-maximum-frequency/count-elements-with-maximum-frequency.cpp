class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> m;
        int maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            maxi=max(maxi,m[nums[i]]);
        }
        int ans=0;
        for(auto i:m)
        {
            if(i.second==maxi)
            {
                ans+=i.second;
            }
        }
        return ans;
    }
};