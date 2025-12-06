class Solution {
public:

    static bool cmp(pair<int,int> a,pair<int,int> b)
    {
        return (a.first)>(b.first);
    }

    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        long long ans=0;
        int n=technique1.size();
        vector<int> index(n,0);
        for(int i=0;i<n;i++)
        {
            if(technique1[i]>=technique2[i])
            {
                index[i]=1;
                ans+=technique1[i];
                if(k>0) k--;
            }
        }
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++)
        {
            if(!index[i])
            {
                temp.push_back({technique1[i]-technique2[i],i});
            }
        }
        sort(temp.begin(),temp.end(),cmp);
        for(auto i:temp)
        {
            cout<<i.first<<" ";
        }
        for(auto i:temp)
        {
            if(k==0)
            {
                break;
            }
            int curridx=i.second;
            ans+=technique1[curridx];
            index[curridx]=1;
            k--;
        }
        for(int i=0;i<n;i++)
        {
            if(!index[i])
            {
                ans+=technique2[i];
            }
        }
        return ans;
        
    }
};