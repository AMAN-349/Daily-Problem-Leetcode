class Solution {
public:
    vector<int> par;

    int find(int x) {
        if (par[x] == x)
            return x;
        return find(par[x]);
    }

    void union_set(int x, int y) {
        int a1 = find(x);
        int a2 = find(y);
        if (a1 == a2)
            return;
        if (a1 < a2)
            par[a2] = a1;
        else
            par[a1] = a2;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        par.resize(26);
        for (int i = 0; i < 26; i++) {
            par[i] = i;
        }

        for (int i = 0; i < s1.size(); i++) {
            union_set(s1[i] - 'a', s2[i] - 'a');
        }

        string ans = "";
        for (char c : baseStr) {
            ans += (char)(find(c - 'a') + 'a');
        }

        return ans;
    }
};
