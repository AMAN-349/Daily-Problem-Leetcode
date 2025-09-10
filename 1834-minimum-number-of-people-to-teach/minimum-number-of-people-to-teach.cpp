class Solution {
public:

    int findMin(vector<vector<int>>& unknown,unordered_map<int, unordered_set<int>>& m,int n)
    {
        unordered_set<int> pl;
        int cnt=0;
        for(auto i:unknown)
        {
            pl.insert(i[0]);
            pl.insert(i[1]);
        }
        vector<int> teachCount(n+1, 0);
        for(int i=1;i<=n;i++)
        {
            int cnt=0;
            for(auto j:pl)
            {
                if (!m[j].count(i)) cnt++;
            }
            teachCount[i]=cnt;
        }
        return *min_element(teachCount.begin()+1,teachCount.end());
    }

    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_map<int, unordered_set<int>> m;
        int cnt = 1;
        for (auto &i : languages) {
            for (int l : i) {
                m[cnt].insert(l);
            }
            cnt++;
        }
        vector<vector<int>> unknown;
        for(auto i:friendships)
        {
            int temp1=i[0];
            int temp2=i[1];
            auto &s1 = m[temp1];
            auto &s2 = m[temp2];
    
            bool ok = false;
            if (s1.size() <= s2.size()) {
                for (int l : s1) {
                    if (s2.count(l)) { ok = true; break; }
                }
            } else {
                for (int l : s2) {
                    if (s1.count(l)) { ok = true; break; }
                }
            }
            if (!ok) {
                unknown.push_back({temp1, temp2});
            }
        }
        for(auto i:unknown)
        {
            cout<<i[0]<<i[1]<<" ";
        }
        return findMin(unknown,m,n);
    }
};