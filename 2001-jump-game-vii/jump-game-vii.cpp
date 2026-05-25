class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        if(minJump>maxJump) return false;
        int jump=0;
        int minijump=0;
        vector<bool> visited(n, false);
        visited[0] = true;
        queue<int> q;
        int farthest=0;
        q.push(0);
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            if(temp==n-1) return true;

            int left=max(temp+minJump,farthest);
            int right=min(temp+maxJump,n-1);

            if(left<n){
                for(int i=left;i<=right;i++)
                {
                    if(s[i]=='0' && !visited[i])
                    {
                        visited[i]=true;
                        q.push(i);
                    }
                }
            }
            farthest=right+1;
        }
        return false;
    }
};