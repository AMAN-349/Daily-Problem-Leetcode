class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int ans=0;
        int m=queries.size();
        priority_queue<int> available;
        priority_queue<int,vector<int>,greater<int>> used;
        sort(queries.begin(),queries.end());
        int pos=0;
        for(int i=0;i<n;i++)
        {
            while(pos<m && queries[pos][0]==i)
            {
                available.push(queries[pos][1]);
                pos++;
            }
            nums[i]-=used.size();

            while(nums[i]>0 && !available.empty() && available.top()>=i)
            {
                used.push(available.top());
                available.pop();
                nums[i]--;
                ans++;
            }

            if(nums[i]>0) return -1;

            while(!used.empty() && used.top()==i)
            {
                used.pop();
            }
        }
        return m-ans;
    }
};