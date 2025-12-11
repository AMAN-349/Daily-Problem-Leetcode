class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int,set<int>> m1;
        map<int,set<int>> m2;
        for(auto i:buildings)
        {
            int x=i[0];
            int y=i[1];
            m1[x].insert(y);
            m2[y].insert(x);
        }
        int ans=0;
        for(auto i:buildings)
        {
            int x=i[0];
            int y=i[1];
            set<int>& s1=m1[x];
            set<int>& s2=m2[y];
            auto end1=s1.end();
            auto end2=s2.end();
            end1--;
            end2--;
            if(s2.find(x)!=end2 && s2.find(x)!=s2.begin() && s1.find(y)!=end1 && s1.find(y)!=s1.begin())
            {
                ans++;
            }
        }
        return ans;
    }
};