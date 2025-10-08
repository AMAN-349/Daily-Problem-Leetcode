class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        vector<int> ans(n);
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++)
        {
            long long val = ceil((double)success / spells[i]);
            cout<<val;
            auto ind=lower_bound(potions.begin(),potions.end(),val);
            cout<<(ind-potions.begin())<<" ";
            if(ind==potions.end())
            {
                ans[i]=0;
            }
            else{
                ans[i]=potions.size()-(ind-potions.begin());
            }
        }
        return ans;
    }
};