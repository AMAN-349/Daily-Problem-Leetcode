class Solution {
public:
    
    bool check(vector<int> v)
    {
        for(int i=1;i<v.size();i++)
        {
            if(v[i]<=v[i-1])
            {
                return false;
            }
        }
        return true;
    }


    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k==1) return true;
        int n = nums.size();
        for (int i = 0; i <= n - k; i++) {
            vector<int> sub1(nums.begin() + i, nums.begin() + i + k);
            int j=i+k;
            if(j+k<=n)
            {
                vector<int> sub2(nums.begin() + i + k, nums.begin() + i + k + k);
                if (check(sub1) && check(sub2)) {
                    return true;
                }
            }
        }
        return false;

    }
};