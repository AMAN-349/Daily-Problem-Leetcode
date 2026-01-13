class Solution {
public:

    bool check(double mid,vector<vector<int>>& squares)
    {
        double lower=0;
        double upper=0;
        for (auto &sq : squares) {
            double y = sq[1];
            double len = sq[2];

            if (y + len <= mid) {
                lower += len * len;
            }
            else if (y >= mid) {
                upper += len * len;
            }
            else {
                double below = mid - y;
                lower += below * len;
                upper += (len - below) * len;
            }
        }
        return lower >= upper;
    }

    double separateSquares(vector<vector<int>>& squares) {
        int n=squares.size();
        double l=0;
        double h=1e9;

        while(h-l>1e-6)
        {
            double m=(l+h)/2.0;
            if(check(m,squares))
            {
                h=m;
            }
            else{
                l=m;
            }
        }
        return l;
    }
};