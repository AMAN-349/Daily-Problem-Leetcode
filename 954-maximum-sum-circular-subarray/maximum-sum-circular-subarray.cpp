class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int n=arr.size();
        int ans=arr[0];
        int temp=arr[0];
        for(int i=1;i<n;i++)
        {
            temp+=arr[i];
            temp=max(temp,arr[i]);
            ans=max(ans,temp);
        }
        
        int ans2=arr[0];
        int totalsum=arr[0];
        int temp2=arr[0];
        for(int i=1;i<n;i++)
        {
            totalsum+=arr[i];
            temp2+=arr[i];
            temp2=min(temp2,arr[i]);
            ans2=min(ans2,temp2);
        }
        if(ans<0)
        {
            return ans;
        }
        return max(ans,totalsum-ans2);
    }
};