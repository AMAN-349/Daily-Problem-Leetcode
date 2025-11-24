class Solution {
public:

    static bool cmp(vector<int>& a,vector<int>& b)
    {
        if((a[1]-a[0])==(b[1]-b[0]))
        {
            return a[0]<b[0];
        }
        return (a[1]-a[0])<(b[1]-b[0]);
    }

    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        for(int i=1;i<n;i++)
        {
            ans.push_back({arr[i-1],arr[i]});
        }
        sort(ans.begin(),ans.end(),cmp);
        vector<vector<int>> res;
        int diff=-1;
        for(auto i:ans)
        {
            int curr=i[1]-i[0];
            if(diff==-1 || diff==curr)
            {
                res.push_back(i);
                diff=curr;
            }
        }
        return res;
    }
};