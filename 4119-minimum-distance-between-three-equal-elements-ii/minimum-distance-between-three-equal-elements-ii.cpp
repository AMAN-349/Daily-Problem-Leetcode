class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        map<int,vector<int>> m;

        for(int i=0;i<n;i++)
        {
            m[nums[i]].push_back(i);
        }

        int ans=INT_MAX;

        for(auto i:m)
        {
            if(i.second.size()<3)
            {
                continue;
            }
            vector<int>& v=i.second;
            int p1=0;
            int p2=1;
            int p3=2;
            while(p3<v.size())
            {
                ans=min(ans,abs(v[p2]-v[p1])+abs(v[p3]-v[p2])+abs(v[p3]-v[p1]));
                p1++;
                p2++;
                p3++;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};