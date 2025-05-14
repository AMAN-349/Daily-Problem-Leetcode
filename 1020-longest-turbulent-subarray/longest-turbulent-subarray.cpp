class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;

        int l = 0, r = 1;
        int ans = 1;

        while (r < n) {
            int temp = (arr[r - 1] > arr[r]) ? -1 : (arr[r - 1] < arr[r]) ? 1 : 0;

            if (temp == 0) {
                l = r;
            } else {
                if (r == n - 1 || temp * ((arr[r] > arr[r + 1]) ? -1 : (arr[r] < arr[r + 1]) ? 1 : 0) != -1) {
                    ans = max(ans, r - l + 1);
                    l = r;
                }
            }
            r++;
        }

        return ans;
    }
};
