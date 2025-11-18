class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n+1);
        for(auto i:nums)
        {
            v[i]++;
        }
        int dup,mis;
        for(int i=1;i<=n;i++)
        {
            if(v[i]==0) mis=i;
            if(v[i]==2) dup=i;
        }
        return {dup,mis};

    }
};