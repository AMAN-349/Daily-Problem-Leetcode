class Solution {
public:

    pair<int,int> find(vector<int>& nums)
    {
        int ans=0;
        unordered_set<int> s(nums.begin(),nums.end());
        int start,end;
        for(auto i:s)
        {
            int temp=i;
            int cnt=1;
            if(!s.count(i-1))
            {
                while(s.find(++temp)!=s.end())
                {
                    cnt++;
                }
            }
            if(cnt>ans){
                ans=max(ans,cnt);
                start=i;
                end=temp-1;
            }
        }
        return {start,end};
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        pair<int,int> l1=find(hBars);
        pair<int,int> l2=find(vBars);
        int res=min((l1.second-l1.first+2),(l2.second-l2.first+2));
        return res*res;
    }
};