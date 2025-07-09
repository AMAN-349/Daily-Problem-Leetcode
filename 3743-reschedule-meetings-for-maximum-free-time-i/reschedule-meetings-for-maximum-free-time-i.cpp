class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> v;
        int n=startTime.size();
        for(int i=0;i<=n;i++)
        {
            if(i==0)
            {
                v.push_back(startTime[i]);
            }
            else if(i==n)
            {
                v.push_back(eventTime-endTime[i-1]);
            }
            else{
                v.push_back(startTime[i]-endTime[i-1]);
            }
        }
        int ans=0;
        int temp=0;
        int i=0;
        int j=0;
        for(j=0;j<=k;j++)
        {
            temp+=v[j];
        }
        ans=max(ans,temp);
        while(j<v.size())
        {
            temp+=v[j];
            temp-=v[i];
            ans=max(ans,temp);
            i++;
            j++;
        }
        return ans;
    }
};