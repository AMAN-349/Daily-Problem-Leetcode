class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int l) {
        set<int> s;
        int n = nums.size();
        
        for(int j = 0; j < n; j++)
        {
            if(nums[j] == key)
            {
                int left = max(0, j - l);
                int right = min(n - 1, j + l);
                
                for(int i = left; i <= right; i++)
                {
                    s.insert(i);
                }
            }
        }
        
        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};
