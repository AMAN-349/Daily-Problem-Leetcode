class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> v;
        for(auto i:nums)
        {
            if(i>=0)
            {
                v.push_back(i);
            }
        }
        int n=v.size();
        if(n==0)
        {
            return nums;
        }
        k=k%n;
        if(k!=0){
            reverse(v.begin(), v.begin() + k);
            reverse(v.begin() + k, v.end());
            reverse(v.begin(), v.end());
        }
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)
            {
                nums[i]=v[j];
                j++;
            }
        }
        cout<<k<<" ";
        return nums;
    }
};