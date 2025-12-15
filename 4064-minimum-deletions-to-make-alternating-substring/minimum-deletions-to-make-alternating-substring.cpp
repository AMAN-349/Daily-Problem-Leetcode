class Solution {
public:

    void update(vector<int>& prefix, int ind, int val, int n)
    {
        while (ind <= n) {
            prefix[ind] += val;
            ind += (ind & -ind);
        }
    }

    int sum(vector<int>& prefix, int ind)
    {
        int s = 0;
        while (ind > 0) {
            s += prefix[ind];
            ind -= (ind & -ind);
        }
        return s;
    }

    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int> prefix(n+1,0);
        vector<int> ans;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                update(prefix, i + 1, 1, n);
            }
        }

        for(auto i:queries)
        {
            if(i[0]==1)
            {
                int pos=i[1];
                char prev=s[i[1]];
                if(pos>0)
                {
                    if(s[pos]==s[pos-1])
                    {
                        update(prefix,pos+1,-1,n);
                    }
                    else{
                        update(prefix,pos+1,1,n);
                    }
                }
                if(pos<n-1)
                {
                    if(s[pos]==s[pos+1])
                    {
                        update(prefix,pos+2,-1,n);
                    }
                    else{
                        update(prefix,pos+2,1,n);
                    }
                }
                if(s[pos]=='A')
                {
                    s[pos]='B';
                }
                else{
                    s[pos]='A';
                }
            }
            else{
                int r=i[2];
                int l=i[1];
                int res=sum(prefix,r+1)-sum(prefix,l+1);
                ans.push_back(res);
            }
        }
        return ans;

    }
};