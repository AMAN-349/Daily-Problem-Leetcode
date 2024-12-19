class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int pre[n];
        pre[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=max(pre[i-1],arr[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(pre[i]==i)
            {
                ans++;
            }
        }
        return ans;
    }
};