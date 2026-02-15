class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int,int> m;
        for(auto i:bulbs)
        {
            if(m.count(i))
            {
                if(m[i]==0)
                {
                    m[i]=1;
                }
                else{
                    m[i]=0;
                }
            }
            else{
                m[i]=1;
            }
        }
        vector<int> ans;
        for(auto i:m)
        {
            if(i.second==1)
            {
                ans.push_back(i.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};