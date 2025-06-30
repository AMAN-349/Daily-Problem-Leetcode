class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        if(m.size()==1)
        {
            return 0;
        }
        int ans=0;
        auto it1=m.begin();
        auto it = m.begin();
        ++it;
        for(;it!=m.end();it++)
        {
            if((*it).first-(*it1).first==1)
            {
                ans=max(ans,(*it).second+(*it1).second);
            }
            it1++;
        }
        return ans;
    }
};