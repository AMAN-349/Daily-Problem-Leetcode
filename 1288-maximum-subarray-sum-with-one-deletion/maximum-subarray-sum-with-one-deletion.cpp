class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        if(n==1)
        {
            return arr[0];
        }
        int res=INT_MIN;
        int prenotdeleted=arr[0];
        int predeleted=0;
        for(int i=1;i<n;i++)
        {
            predeleted=max(prenotdeleted,predeleted+arr[i]);//this is if we deletedd previously
            prenotdeleted=max(prenotdeleted+arr[i],arr[i]);//this is simple
            int curr=max(prenotdeleted,predeleted);
            res=max(res,curr);
        }
        return res;
    }
};