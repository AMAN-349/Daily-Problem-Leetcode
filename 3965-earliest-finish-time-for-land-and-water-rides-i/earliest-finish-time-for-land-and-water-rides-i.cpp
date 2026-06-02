class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int res=0;

                if(landStartTime[i]<waterStartTime[j])
                {
                    res+=landStartTime[i];
                    res+=landDuration[i];
                    if(waterStartTime[j]>res)
                    {
                        res+=(waterStartTime[j]-res);
                    }
                    res+=waterDuration[j];
                }
                else{
                    res+=waterStartTime[j];
                    res+=waterDuration[j];
                    if(landStartTime[i]>res)
                    {
                        res+=(landStartTime[i]-res);
                    }
                    res+=landDuration[i];
                }
                
                ans=min(ans,res);
            }
        }
        return ans;
    }
};