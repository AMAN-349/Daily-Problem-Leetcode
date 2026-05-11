class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;

        for(auto i:nums)
        {
            vector<int> temp;
            while(i>0)
            {
                temp.push_back(i%10);
                i=i/10;
            }
            reverse(temp.begin(),temp.end());
            for(auto i:temp)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};