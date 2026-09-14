class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        vector<pair<int,int>> v1;
        vector<pair<int,int>> v2;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(img1[i][j] == 1)
                    v1.push_back({i, j});

                if(img2[i][j] == 1)
                    v2.push_back({i, j});
            }
        }

        map<pair<int,int>, int> mp;

        int ans = 0;

        for(auto [x1, y1] : v1) {
            for(auto [x2, y2] : v2) {

                int dr = x2 - x1;
                int dc = y2 - y1;

                mp[{dr, dc}]++;

                ans = max(ans, mp[{dr, dc}]);
            }
        }

        return ans;
    }
};