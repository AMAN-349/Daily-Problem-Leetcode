class Solution {
public:
    int maxDiff(int num) {
        vector<int> v;
        while (num > 0) {
            v.push_back(num % 10);
            num = num / 10;
        }
        reverse(v.begin(), v.end());

        vector<int> dup = v;
        int temp;
        int i = 0;

        while (i < v.size() && v[i] == 9) {
            i++;
        }
        if (i < v.size()) {
            temp = v[i];
        }

        for (int j = 0; j < v.size(); j++) {
            if (v[j] == temp) {
                v[j] = 9;
            }
        }

        i = 0;
        int temp2;
        while (i < dup.size() && (dup[i] == 1 || dup[i]==0)) {
            i++;
        }
        if (i < dup.size()) {
            cout<<"******";
            temp2 = dup[i];
        }

        int val = (i == 0) ? 1 : 0;

        for (int j = 0; j < dup.size(); j++) {
            if (dup[j] == temp2) {
                dup[j] = val;
            }
        }

        int ans1 = 0;
        for (auto k : v) {
            ans1 = ans1 * 10 + k;
        }

        int ans2 = 0;
        for (auto k : dup) {
            ans2 = ans2 * 10 + k;
        }

        cout << ans1 << " " << ans2 << endl;
        return ans1 - ans2;
    }
};
