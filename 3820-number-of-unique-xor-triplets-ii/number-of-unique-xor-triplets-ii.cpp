class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        int mini=0;
        int maxi=*max_element(nums.begin(),nums.end());
        int digits=log2(maxi);
        maxi=(1<<digits);
        maxi*=2;

        if(n==1) return n;

        unordered_set<int> s;

        for(int i=0;i<n-1;i++)
        {
            for(int j=i;j<n;j++)
            {
                s.insert((nums[i]^nums[j]));
            }
        }

        int ans=0;

        for (int target = mini; target <= maxi; target++) {
            bool ok = false;
            for (int j = 0; j < n; j++) {
                if (s.count(nums[j] ^ target)) {
                    ok = true;
                    break;
                }
            }
            if (ok) ans++;
        }

        return ans;
    }
};