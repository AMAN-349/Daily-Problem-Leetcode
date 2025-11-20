class Solution {
public:

    static bool cmp(vector<int>& p1,vector<int>& p2)
    {
        if (p1[1] == p2[1]) return p1[0] > p2[0];
        return p1[1]<p2[1];
    }

    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        for(auto i:intervals)
        {
            cout<<i[0]<<","<<i[1]<<" ";
        }
        vector<int> ans;
        vector<int> temp;
        temp.push_back(intervals[0][1]-1);
        temp.push_back(intervals[0][1]);
        for(int i=1;i<n;i++)
        {
            int cnt=0;
            if(temp[0]>=intervals[i][0] && temp[0]<=intervals[i][1])
            {
                cnt++;
            }
            if(temp[1]<=intervals[i][1] && temp[1]>=intervals[i][0])
            {
                cnt++;
            }
            if(cnt==2)
            {
                continue;
            }
            else if(cnt==1)
            {
                ans.push_back(temp[0]);
                temp[0]=temp[1];
                temp[1]=intervals[i][1];
            }
            else{
                ans.push_back(temp[0]);
                ans.push_back(temp[1]);
                temp[0]=intervals[i][1]-1;
                temp[1]=intervals[i][1];
            }
        }
        ans.push_back(temp[0]);
        ans.push_back(temp[1]);
        return ans.size();
    }
};