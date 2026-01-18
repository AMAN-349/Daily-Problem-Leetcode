class Solution {
public:

    int find(int start,int end,vector<pair<int,int>>& temp,int budget,vector<int>& prefix)
    {
        int ans=0;
        while(start<=end)
        {
            int m=(start+end)/2;
            if(temp[m].first<budget)
            {
                ans=prefix[m];
                start=m+1;
            }
            else{
                end=m-1;
            }
        }
        return ans;
    }

    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        vector<pair<int,int>> temp;
        int n=costs.size();
        for(int i=0;i<n;i++)
        {
            temp.push_back({costs[i],capacity[i]});
        }
        sort(temp.begin(),temp.end());
        vector<int> prefix(n,0);
        prefix[0]=temp[0].second;
        for(int i=1;i<n;i++)
        {
            prefix[i]=max(prefix[i-1],temp[i].second);
        }
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            int sum=0;
            int bud=budget;
            if(temp[i].first<bud)
            {
                sum+=temp[i].second;
                bud-=temp[i].first;
            }
            if((i-1)>=0)
            sum+=find(0,i-1,temp,bud,prefix);
            ans=max(ans,sum);
        }
        return ans;
    }
};