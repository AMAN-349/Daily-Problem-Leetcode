class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(m.count(target-nums[i]))
            {
                ans.push_back(i);
                ans.push_back(m[target-nums[i]]);
                return ans;
            }
            m[nums[i]]=i;
        }
        return ans;
    }
};