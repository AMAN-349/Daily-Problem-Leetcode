class Solution {
public:

    double area(vector<int>& a, vector<int>& b, vector<int>& c) {
        return 0.5 * abs(
            a[0]*(b[1]-c[1]) +
            b[0]*(c[1]-a[1]) +
            c[0]*(a[1]-b[1])
        );
    }

    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        int n = points.size();
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {
                    ans = max(ans, area(points[i], points[j], points[k]));
                }
            }
        }
        return ans;
    }
};
