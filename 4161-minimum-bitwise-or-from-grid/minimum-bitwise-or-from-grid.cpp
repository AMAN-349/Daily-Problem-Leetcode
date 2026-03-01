class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int ans = 0;
        int forbidden = 0;
        
        for (int bit = 17; bit >= 0; --bit) {
            int testForbidden = forbidden | (1 << bit);            
            bool possible = true;

            for (auto &row : grid) {
                bool found = false;

                for (int num : row) {
                    if ((num & testForbidden) == 0) {
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                forbidden = testForbidden; 
            } else {
                ans |= (1 << bit);   
            }
        }

        return ans;
    }
};