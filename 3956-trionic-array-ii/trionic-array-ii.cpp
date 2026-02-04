class Solution {
public:
    long long res=LLONG_MIN;
    vector<long long> prefix;
    vector<long long> incL;
    vector<long long> incR;
    
    long long find(int p1, int p2, int p3, int p, vector<int>& nums)
    {
        int l = p - p1 + 1;
        int q = p + p2 - 1;
        int r = q + p3 - 1;

        long long ans = 0;
        long long temp=0;
        long long left=LLONG_MIN;
        ans=incL[p-1]+nums[p];
        ans+=prefix[q]-prefix[p];
        ans+=incR[q+1];

        return ans;
    }



    long long maxSumTrionic(vector<int>& nums) {
        int n=nums.size();
        prefix.resize(n,0);
        vector<int> prefinc;
        vector<int> suffinc(n,1);
        vector<int> suffdec(n,1);

        incL.resize(n,0);
        incR.resize(n,0);

        incL[0] = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1])
                incL[i] = max(nums[i]*1LL,incL[i-1] + nums[i]);
            else
                incL[i] = nums[i];
        }

        incR[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1])
                incR[i] = max(incR[i+1] + nums[i],nums[i]*1LL);
            else
                incR[i] = nums[i];
        }


        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=nums[i]+prefix[i-1];
        }

        prefinc.push_back(1);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                prefinc.push_back(prefinc[i-1]+1);
            }
            else{
                prefinc.push_back(1);
            }
        }
        suffinc[n-1]=1;
        suffdec[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>nums[i+1])
            {
                suffdec[i]+=suffdec[i+1];
            }
            if(nums[i]<nums[i+1])
            {
                suffinc[i]+=suffinc[i+1];
            }
        }
        long long ans=LLONG_MIN;
        for (int i = 0; i < n; i++)
        {
            int p1 = prefinc[i];
            if (p1 <= 1 || i - p1 + 1 < 0) continue;

            int p2 = suffdec[i];
            if (p2 <= 1) continue;

            int q = i + p2 - 1;
            if (q >= n) continue;

            int p3 = suffinc[q];
            if (p3 <= 1 || q + p3 - 1 >= n) continue;

            ans = max(ans, find(p1, p2, p3, i, nums));
            res=max(res,ans);
        }

        return res;

    }
};