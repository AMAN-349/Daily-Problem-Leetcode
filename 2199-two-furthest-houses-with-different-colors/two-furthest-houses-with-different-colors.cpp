class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans=0;
        int n=colors.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(colors[i]!=colors[j])
                {
                    ans=max(ans,abs(i-j));
                }
                if(ans>=n)
                {
                    return ans;
                }
            }
        }
        return ans;
    }
};