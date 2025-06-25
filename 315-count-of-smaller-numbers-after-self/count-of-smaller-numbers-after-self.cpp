class Solution {
public:
    vector<pair<int,int>> temp;

    void merge(vector<pair<int,int>>& v, int s1, int e1, int s2, int e2, vector<int>& ans) {
        int c = s1;
        int i = s1;
        int j = s2;
        vector<int> dup(e1 - s1 + 1, 0);  // tracks how many times v[i] lost to right side
        int offset = s1;  // to shift local indices to 0-based dup array

        while(i <= e1 && j <= e2) {
            if(v[i].first <= v[j].first) {
                temp[c++] = v[i++];
            } else {
                dup[i - offset] += 1;
                temp[c++] = v[j++];
            }
        }

        for(int k = 1; k <= e1 - s1; k++) {
            dup[k] += dup[k - 1];
        }

        for(int k = s1; k <= e1; ++k) {
            ans[v[k].second] += dup[k - offset];
        }

        while(i <= e1) temp[c++] = v[i++];
        while(j <= e2) temp[c++] = v[j++];

        for(int k = s1; k <= e2; ++k)
            v[k] = temp[k];
    }

    void mergesort(vector<pair<int,int>>& v, int l, int r, vector<int>& ans) {
        if(l >= r) return;
        int m = (l + r) / 2;
        mergesort(v, l, m, ans);
        mergesort(v, m + 1, r, ans);
        merge(v, l, m, m + 1, r, ans);
    }

    vector<int> countSmaller(vector<int>& num) {
        int n = num.size();
        vector<pair<int,int>> nums;
        for(int i = 0; i < n; i++)
            nums.push_back({num[i], i});
        
        temp.assign(n, {0, 0});
        vector<int> ans(n, 0);
        
        mergesort(nums, 0, n - 1, ans);

        return ans;
    }
};
