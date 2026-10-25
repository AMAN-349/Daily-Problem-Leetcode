class Solution {
public:
    long long countMagicalPairs(string s) {
        int n=s.size();

        vector<vector<int>> left(n,vector<int>(27,0));
        vector<vector<int>> right(n,vector<int>(27,0));

        vector<int> last(27,-1);

        for(int i=0;i<n;i++)
        {
            last[s[i]-'a']=i;

            vector<int> pos;

            for(int j=0;j<27;j++)
            {
                if(last[j]!=-1)
                {
                    pos.push_back(last[j]);
                }
            }

            int d=pos.size();

            sort(pos.rbegin(),pos.rend());

            for(int k=1;k<d;k++)
            {
                left[i][k]=pos[k-1]-pos[k];
            }
            left[i][d]=pos[d-1]+1;
        }
        vector<int> nxt(27, -1);
        for(int i=n-1;i>=0;i--)
        {
            nxt[s[i]-'a']=i;

            vector<int> pos;

            for(int j=0;j<27;j++)
            {
                if(nxt[j]!=-1)
                {
                    pos.push_back(nxt[j]);
                }
            }

            int d=pos.size();
            sort(pos.begin(),pos.end());

            for(int k=1;k<d;k++)
            {
                right[i][k]=pos[k]-pos[k-1];
            }
            right[i][d]=n-pos[d-1];
        }

        long long ans = 0;

        for (int j = 0; j + 1 < n; j++) {
            for (int d = 1; d <= 26; d++) {
                ans += 1LL * left[j][d] * right[j + 1][d];
            }
        }

        return ans;
    }
};