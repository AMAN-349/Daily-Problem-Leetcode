class Solution {
public:
    static bool cmp(vector<int>& v1,vector<int>& v2)
    {
        // if(v1[0]==v2[0])
        // {
        //     return v1[1]<v2[1];
        // }
        return v1[0]<v2[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),cmp);
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++)
        {
            if(ans.back()[1]>=intervals[i][0])
            {
                ans.back()[1]=max(intervals[i][1],ans.back()[1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};