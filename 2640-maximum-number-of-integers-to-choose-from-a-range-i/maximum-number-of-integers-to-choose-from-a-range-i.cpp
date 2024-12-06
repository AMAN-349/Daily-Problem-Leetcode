class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans=0;
        int res=0;
        for(int i=1;i<=n;i++)
        {
            if(find(banned.begin(),banned.end(),i)==banned.end())
            {
                res+=i;
                if(res<=maxSum)
                {
                    ans++;
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};