class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1)
        {
            return false;
        }
        map<int,int> m;
        for(int i=0;i<=min(k,n-1);i++)
        {
            if(m.find(nums[i])!=m.end())
            {
                return true;
            }
            m[nums[i]]=1;
        }
        int i=0;
        int j=k+1;
        while(j<n)
        {
            if(m.count(nums[i]))
            {
                m[nums[i]]--;
                if(m[nums[i]]==0)
                {
                    m.erase(nums[i]);
                }
            }
            if(m.find(nums[j])!=m.end())
            {
                return true;
            }
            m[nums[j]]=1;
            j++;
            i++;
        }
        return false;
    }
};