class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int> m;
        int sum=0;
        int cnt=0;

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum==goal) cnt++;
            if(m.find(sum-goal)!=m.end())
            {
                cnt+=m[sum-goal];
            }
            m[sum]++;
        }
        return cnt;
    }
};