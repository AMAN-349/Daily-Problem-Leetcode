class Solution {
public:
    bool checkSubarraySum(vector<int>& v, int k) {
        int n=v.size();
        vector<int> prefix(n,0);
        unordered_map<int,int> m;
        prefix[0]=v[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=v[i]+prefix[i-1];
        }
        m[0]=-1;
        for(int i=0;i<n;i++)
        {
            int rem=prefix[i]%k;
            if(m.find(rem)!=m.end())
            {
                int ind=m[rem];
                if((i-ind)>=2)
                {
                    return true;
                }
            }
            else{
                m[rem]=i;
            }
        }
        return false;
    }
};