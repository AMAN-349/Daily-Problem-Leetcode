class Solution {
public:

    int findmin(int l, int r, vector<long long>& power)
    {
        return *min_element(power.begin() + l, power.begin() + r + 1);
    }

    void add(int l,int r,vector<long long>& power,long long ans)
    {
        for(int i=l;i<=r;i++)
        {
            power[i]+=ans;
        }
    }

    bool isvalid(vector<long long>& power, long long k, long long ans, int r)
    {
        int n = power.size();
        vector<long long> diff(n, 0);
        long long windowAdd = 0;

        for(int i = 0; i < n; i++)
        {
            if(i - r - 1 >= 0)
                windowAdd -= diff[i - r - 1];

            long long currPower = power[i] + windowAdd;

            if(currPower < ans)
            {
                long long need = ans - currPower;
                if(k < need)
                    return false;

                k -= need;

                int pos = min(n - 1, i + r);
                diff[pos] += need;
                windowAdd += need;
            }
        }
        return true;
    }

    long long bin_search(long long mini,long long maxi,vector<long long>& stations,long long k,int range)
    {
        long long l=mini;
        long long r=maxi;
        long long ans=mini;

        while(l<=r)
        {
            long long mid = l + (r - l) / 2;
            if(isvalid(stations,k,mid,range))
            {
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        int n=stations.size();
        vector<long long> prefix(n,0);
        vector<long long> suffix(n,0);
        vector<long long> stationsLL(n,0);

        for(int i=0;i<n;i++)
        {
            stationsLL[i] = stations[i];
        }

        prefix[0]=stationsLL[0];
        suffix[n-1]=stationsLL[n-1];
        for(int i=1;i<n;i++)
        {
            prefix[i]=stationsLL[i]+prefix[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=stationsLL[i]+suffix[i+1];
        }
        for(int i=0;i<n;i++)
        {
            int left=max(0,i-r);
            int right=min(i+r,n-1);
            long long leftsum=suffix[left]-suffix[i];
            long long rightsum=prefix[right]-prefix[i];
            stationsLL[i]+=leftsum+rightsum;
        }

        long long mini=*min_element(stationsLL.begin(),stationsLL.end());
        long long maxi=*max_element(stationsLL.begin(),stationsLL.end());
        
        maxi+=k;
        cout<<maxi<<" ";

        return bin_search(mini,maxi,stationsLL,k,r);
    }
};
