class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,unordered_set<int>> m;
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++)
        {
            if(freq.count(nums[i]))
            {
                int old=freq[nums[i]];
                m[old].erase(nums[i]);
                freq[nums[i]]++;
                m[freq[nums[i]]].insert(nums[i]);
            }
            else{
                freq[nums[i]]++;
                m[freq[nums[i]]].insert(nums[i]);
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            int cnt=freq[nums[i]];
            if(m[cnt].size()==1)
            {
                return *(m[cnt].begin());
            }
        }
        return -1;
    }
};