class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        queue<int> q;
        vector<int> vis(n,false);
        q.push(0);
        vis[0]=true;
        int jump=0;

        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]].push_back(i);
        }

        while(!q.empty())
        {
            int n2=q.size();
            for(int i=0;i<n2;i++){
                int temp=q.front();
                q.pop();
                if(temp==n-1) return jump;

                if(temp>0 && !vis[temp-1]) 
                {
                    vis[temp-1]=true;
                    q.push(temp-1);
                }
                if(temp<n-1 && !vis[temp+1]) {
                    vis[temp+1]=true;
                    q.push(temp+1);
                }
                if(m.find(arr[temp])!=m.end()){
                    for(auto i:m[arr[temp]])
                    {
                        if(!vis[i])
                        {
                            vis[i]=true;
                            q.push(i);
                        }
                    }
                    m.erase(arr[temp]);
                }
            }
            jump++;
        }
        return jump;

    }
};