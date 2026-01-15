class Solution {
public:
    
    unordered_map<int,int> m;
    int bound;
    Solution(int n, vector<int>& blacklist) {
        int k=blacklist.size();
        unordered_set<int> s(blacklist.begin(),blacklist.end());
        bound=n-k;
        int next=bound;
        for(auto b:blacklist)
        {
            if(b<bound)
            {
                while(s.find(next)!=s.end())
                {
                    next++;
                }
                m[b]=next;
                next++;
            }
        }
    }
    
    int pick() {
        int ind=rand()%bound;
        if(m[ind])
        {
            return m[ind];
        }
        return ind;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */