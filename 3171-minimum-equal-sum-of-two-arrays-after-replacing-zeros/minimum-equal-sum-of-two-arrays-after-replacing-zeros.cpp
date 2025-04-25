class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int cnt1=0;
        int cnt2=0;
        long long sum1=0;
        long long sum2=0;
        for(auto i:nums1)
        {
            if(i==0)
            {
                cnt1++;
            }
            if(i==0)
            {
                sum1+=1;
            }
            else{
            sum1+=i;
            }
        }
        for(auto i:nums2)
        {
            if(i==0)
            {
                cnt2++;
            }
            if(i==0)
            {
                sum2+=1;
            }
            else{
            sum2+=i;
            }
        }
        if(sum1>sum2 && cnt2==0)
        {
            return -1;
        }
        if(sum1<sum2 && cnt1==0)
        {
            return -1;
        }
        return max(sum1,sum2);

    }
};