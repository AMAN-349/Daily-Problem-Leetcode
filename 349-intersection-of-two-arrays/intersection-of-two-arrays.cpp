class Solution {
public:
    vector<int> intersection(vector<int>& v1, vector<int>& v2) {
        int n = v1.size();
        int m = v2.size();
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        int i = 0, j = 0;
        vector<int> ans;

        while (i < n && j < m) {
            int temp1 = v1[i];
            int temp2 = v2[j];

            if (temp1 < temp2) {
                while (i < n && v1[i] == temp1) i++;
            } 
            else if (temp1 > temp2) {
                while (j < m && v2[j] == temp2) j++;
            } 
            else {
                ans.push_back(temp1); 
                while (i < n && v1[i] == temp1) i++;
                while (j < m && v2[j] == temp2) j++;
            }
        }
        return ans;
    }
};
