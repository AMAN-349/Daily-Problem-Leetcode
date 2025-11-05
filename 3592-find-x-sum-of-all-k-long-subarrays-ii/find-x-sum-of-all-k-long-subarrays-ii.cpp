class Solution {
public:

    static bool cmp2(const pair<int,int>& a, const pair<int,int>& b) {
        if(a.second == b.second)
            return a.first > b.first; 
        return a.second > b.second; 
    }

    struct cmp {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            if(a.second == b.second)
                return a.first > b.first;
            return a.second > b.second;  
        }
    };

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        map<int,int> m;
        int n = nums.size();

        for(int i = 0; i < k; i++)
            m[nums[i]]++;

        vector<pair<int,int>> v;
        for(auto &p : m)
            v.push_back({p.first, p.second});
        sort(v.begin(), v.end(), cmp2);

        set<pair<int,int>, cmp> s1, s2;
        int i = 0;
        for(i = 0; i < min((int)v.size(), x); i++)
            s1.insert(v[i]);
        for(; i < v.size(); i++)
            s2.insert(v[i]);

        long long ans = 0;
        for(auto &it : s1)
            ans += 1LL * it.first * it.second;

        vector<long long> res;
        res.push_back(ans);

        for(int i = 0; i + k < n; i++) {
            int outval = nums[i];
            int inval = nums[i + k];

            if(s1.find({outval, m[outval]}) != s1.end()) {
                s1.erase({outval, m[outval]});
                ans -= 1LL * outval;
                m[outval]--;
                s1.insert({outval, m[outval]});
            } else {
                s2.erase({outval, m[outval]});
                m[outval]--;
                s2.insert({outval, m[outval]});
            }

            if(s1.find({inval, m[inval]}) != s1.end()) {
                s1.erase({inval, m[inval]});
                m[inval]++;
                ans += 1LL * inval;
                s1.insert({inval, m[inval]});
            } else {
                s2.erase({inval, m[inval]});
                m[inval]++;
                s2.insert({inval, m[inval]});
            }

            if(!s1.empty() && !s2.empty()) {
                auto p1 = *s1.rbegin();
                auto p2 = *s2.begin();
                if(p2.second > p1.second || 
                   (p2.second == p1.second && p2.first > p1.first)) {
                    s1.erase(p1);
                    s2.erase(p2);
                    ans -= 1LL * p1.first * p1.second;
                    ans += 1LL * p2.first * p2.second;
                    s1.insert(p2);
                    s2.insert(p1);
                }
            }
            while(!s2.empty() && s1.size()<x) {
                auto maxInS2 = *s2.begin();
                s2.erase(maxInS2);
                s1.insert(maxInS2);
                ans += 1LL * maxInS2.first * maxInS2.second;
            }
            // for(auto i:s1)
            // {
            //     cout<<i.first<<" "<<i.second<<" ";
            // }
            cout<<endl;

            res.push_back(ans);
        }

        return res;
    }
};
