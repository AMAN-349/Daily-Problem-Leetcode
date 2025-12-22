class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        map<int,int> m;
        int st=0;
        for(int i=0;i<n;i++)
        {
            if(m.find(nums[i])!=m.end() && m[nums[i]]>=st)
            {
                st=m[nums[i]]+1;
                m[nums[i]]=i;
            }
            else{
                m[nums[i]]=i;
            }
        }
        int ans=st/3;
        if(st%3!=0)
        {
            ans++;
        }
        return ans;
    }
};