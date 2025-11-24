class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefodd(n,0);
        vector<int> prefeven(n,0);
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                prefeven[i]=nums[i];
            }
            else{
                prefodd[i]=nums[i];
            }
        }
        for(int i=1;i<n;i++)
        {
            prefeven[i]+=prefeven[i-1];
        }
        for(int i=1;i<n;i++)
        {
            prefodd[i]+=prefodd[i-1];
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int oddcount=0;
            int evencount=0;
            if(i-1>=0)
            {
                oddcount+=prefodd[i-1];
                evencount+=prefeven[i-1];
            }
            oddcount+=prefeven[n-1]-prefeven[i];
            evencount+=prefodd[n-1]-prefodd[i];
            if(oddcount==evencount)
            {
                cnt++;
            }
        }
        return cnt;
    }
};