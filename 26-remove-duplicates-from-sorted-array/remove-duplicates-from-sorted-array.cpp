class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> v;
        int i=0;
        int n=nums.size();
        while(i<n)
        {
            int temp=nums[i];
            v.push_back(temp);
            while(i<n && nums[i]==temp)
            {
                i++;
            }
        }
        for(int i=0;i<v.size();i++)
        {
            nums[i]=v[i];
        }
        return v.size();
        
    }
};