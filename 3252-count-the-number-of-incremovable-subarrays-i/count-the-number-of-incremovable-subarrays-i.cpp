class Solution {
public:

    bool check(vector<int> v)
    {
        for(int i=1;i<v.size();i++)
        {
            if(v[i-1]>=v[i])
            {
                return false;
            }
        }
        return true;
    }

    int incremovableSubarrayCount(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {
                vector<int> temp;
                for(int k=0;k<i;k++)
                {
                    temp.push_back(nums[k]);
                }
                for(int k=j+1;k<nums.size();k++)
                {
                    temp.push_back(nums[k]);
                }
                if(check(temp))
                {
                    res++;
                }
            }
        }
        return res;
    }
};