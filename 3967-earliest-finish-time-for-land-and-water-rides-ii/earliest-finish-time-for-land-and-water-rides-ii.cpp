class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();

        vector<pair<int,int>> v;
        for(int i=0;i<m;i++)
        {
            v.push_back({waterStartTime[i],waterDuration[i]});
        }
        vector<pair<int,int>> v1;
        for(int i=0;i<n;i++)
        {
            v1.push_back({landStartTime[i],landDuration[i]});
        }
        sort(v.begin(),v.end());
        sort(v1.begin(),v1.end());
        int ans=INT_MAX;

        vector<int> prefmin(m,0);
        prefmin[0]=v[0].second;
        for(int i=1;i<m;i++)
        {
            prefmin[i]=min(prefmin[i-1],v[i].second);
        }

        vector<int> suffix(m,0);
        suffix[m-1]=v[m-1].first+v[m-1].second;
        for(int i=m-2;i>=0;i--)
        {
            suffix[i]=min(suffix[i+1],v[i].first+v[i].second);
        }

        vector<int> prefmin1(n,0);
        prefmin1[0]=v1[0].second;
        for(int i=1;i<n;i++)
        {
            prefmin1[i]=min(prefmin1[i-1],v1[i].second);
        }

        vector<int> suffix1(n,0);
        suffix1[n-1]=v1[n-1].first+v1[n-1].second;
        for(int i=n-2;i>=0;i--)
        {
            suffix1[i]=min(suffix1[i+1],v1[i].first+v1[i].second);
        }


        for(int i=0;i<n;i++)
        {
            int res=0;
            int st=landStartTime[i];
            int dur=landDuration[i];
            res+=st;
            res+=dur;
            int end=st+dur;
            auto it = lower_bound(v.begin(), v.end(), make_pair(res, INT_MIN));

            int temp=INT_MAX;

            if(it != v.begin())
            {
                int idx = prev(it) - v.begin();
                res += prefmin[idx];
                temp=res;
            }

            if(it != v.end())
            {
                cout<<"hi";
                res = min(temp, suffix[it - v.begin()]);
            }
            ans=min(ans,res);
        }

        for(int i=0;i<m;i++)
        {
            int res=0;
            int st=waterStartTime[i];
            int dur=waterDuration[i];
            res+=st;
            res+=dur;
            int end=st+dur;
            auto it = lower_bound(v1.begin(), v1.end(), make_pair(res, INT_MIN));

            int temp=INT_MAX;

            if(it != v1.begin())
            {
                int idx = prev(it) - v1.begin();
                res += prefmin1[idx];
                temp=res;
            }

            if(it != v1.end())
            {
                cout<<"hi";
                res = min(temp, suffix1[it - v1.begin()]);
            }
            ans=min(ans,res);
        }

        return ans;
    }
};