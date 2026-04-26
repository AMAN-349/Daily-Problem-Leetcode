class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int ind=max_element(nums.begin(),nums.end())-nums.begin();
        long long sum1=accumulate(nums.begin(),nums.begin()+ind+1,0LL);
        long long sum2=accumulate(nums.begin()+ind,nums.end(),0LL);
        if(sum1>sum2) return 0;
        if(sum2>sum1) return 1;
        return -1;
    }
};