class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        vector<long long> pq(100001, 0);
        long long maxdiff=0;

        for(int i=0;i<n;i++)
        {
            long long diff = abs(nums1[i] - nums2[i]);
            pq[diff]++;
            maxdiff=max(maxdiff,diff);
        }

        long long total=1LL*k1+k2;

        for (long long i = maxdiff; i > 0 && total > 0; i--)
            {
                if(pq[i]==0) continue;

                long long op=min(total,pq[i]);

                pq[i]-=op;
                pq[i-1]+=op;
                total-=op;
            }

        long long ans=0;

        for (long long i = 1; i <= maxdiff; i++)
        {
            if(pq[i]>0)
            {
                ans+=pq[i]*i*i;
            }
        }
        return ans;
    }
};