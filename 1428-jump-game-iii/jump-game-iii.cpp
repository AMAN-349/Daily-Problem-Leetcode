class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        queue<int> q;
        q.push(start);
        if(arr[start]==0) return true;
        vector<int> vis(n,false);
        vis[start]=true;

        while(!q.empty())
        {
            int temp=q.front();
            cout<<temp<<" ";
            q.pop();

            if(arr[temp]==0) return true;

            int right=arr[temp]+temp;
            int left=temp-arr[temp];

            if(right<n && !vis[right])
            {
                vis[right]=true;
                q.push(right);
            }
            if(left>=0 && !vis[left])
            {
                vis[left]=true;
                q.push(left);
            }
        }
        return false;

        
    }
};