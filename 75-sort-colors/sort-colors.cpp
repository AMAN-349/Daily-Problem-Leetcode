class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        vector<int> cnt(4,0);
        vector<int> aux(n);
        for(int i=0;i<nums.size();i++)
        {
            cnt[nums[i]]++;
        }
        for(int i=1;i<3;i++)
        {
            cnt[i]+=cnt[i-1];
        }
        for(int i=0;i<n;i++)
        {
            aux[cnt[nums[i]]-1]=nums[i];
            cnt[nums[i]]--;
        }
         for(int i=0;i<n;i++)
        {
            nums[i]=aux[i];
        }
    }
};