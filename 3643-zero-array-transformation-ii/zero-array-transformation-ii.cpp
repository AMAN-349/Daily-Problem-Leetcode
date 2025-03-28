class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int pos=0;
        int sum=0;
        vector<int> diff(n+1,0);
        for(int i=0;i<n;i++)
        {
            while(sum+diff[i]<nums[i])
            {
                if(pos==queries.size())
                {
                    return -1;
                }
                int l=queries[pos][0];
                int m=queries[pos][1];
                int r=queries[pos][2];
                pos++;

                if(m<i)
                {
                    continue;
                }
                diff[max(l,i)]+=r;
                diff[m+1]-=r;

            }
            sum+=diff[i];
        }
        return pos;

    }
};