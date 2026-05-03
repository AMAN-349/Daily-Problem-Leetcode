class Solution {
public:

    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> ans;
        vector<int> closest;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                closest.push_back(i+1);
            }
            else if(i==n-1)
            {
                closest.push_back(i-1);
            }
            else{
                int diff1=abs(nums[i]-nums[i-1]);
                int diff2=abs(nums[i]-nums[i+1]);
                if(diff1<=diff2)
                {
                    closest.push_back(i-1);
                }
                else{
                    closest.push_back(i+1);
                }
            }
        }
        vector<int> prefchain(n,0);
        vector<int> sufchain(n,0);
        for(int i=1;i<n;i++)
        {
            if(closest[i]==i-1)
            {
                prefchain[i]=prefchain[i-1]+1;
            }
            else{
                prefchain[i]=prefchain[i-1]+abs(nums[i]-nums[i-1]);
            }
        }
        for(auto i:prefchain)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        for(int i=n-2;i>=0;i--)
        {
            if(closest[i]==i+1)
            {
                sufchain[i]=sufchain[i+1]+1;
            }
            else
            {
                sufchain[i]=sufchain[i+1]+abs(nums[i]-nums[i+1]);
            }
        }
        for(auto i:sufchain)
        {
            cout<<i<<" ";
        }
        for(auto i:queries)
        {
            int l=i[0];
            int r=i[1];
            int cost=0;
            if(l<r)
            {
                cost=sufchain[l]-sufchain[r];
            }
            else{
                cost=prefchain[l]-prefchain[r];
            }
            ans.push_back(cost);
        }
        return ans;
    }
};