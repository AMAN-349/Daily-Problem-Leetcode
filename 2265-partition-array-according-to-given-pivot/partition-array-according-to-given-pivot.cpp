class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> v1;
        vector<int> v2;
        vector<int> v3;

        for(auto i:nums)
        {
            if(i<pivot)
            {
                v1.push_back(i);
            }
            else if(i==pivot)
            {
                v2.push_back(i);
            }
            else{
                v3.push_back(i);
            }
        }
        vector<int> ans(v1.begin(),v1.end());
        for(auto i:v2)
        {
            ans.push_back(i);
        }
        for(auto i:v3)
        {
            ans.push_back(i);
        }
        return ans;
    }
};