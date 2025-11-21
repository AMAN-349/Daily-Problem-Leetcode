class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int ans=0;
        int sum=gain[0];
        ans=max(ans,sum);
        for(int i=1;i<n;i++)
        {
            sum+=gain[i];
            ans=max(ans,sum);
        }
        return ans;
    }
};