class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int> mp;
        for(auto i:flowers)
        {
            mp[i[0]]+=1;
            mp[i[1]+1]-=1;
        }
        int sum=0;
        for(auto &i:mp)
        {
            sum=sum+i.second;
            i.second=sum;
        }
        vector<int> ans;
        for(auto i:people)
        {
            auto it=mp.lower_bound(i);
            if(it->first==i)
            {
                ans.push_back(it->second);
            }
            else{
                if(it!=mp.begin())
                {
                    it--;
                    ans.push_back(it->second);
                }
                else{
                    ans.push_back(0);
                }
            }
        }
        return ans;
    }
};