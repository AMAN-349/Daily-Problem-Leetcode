class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n=stones.size();
        cout<<n<<" ";
        int forwardjump=0;
        vector<int> vis(n,false);
        int i=0;
        while(i<n-1)
        {
            if(i+2<n)
            {
                forwardjump=max(forwardjump,stones[i+2]-stones[i]);
                vis[i+2]=true;
                i+=2;
            }
            else{
                forwardjump=max(forwardjump,stones[i+1]-stones[i]);
                vis[i+1]=true;
                i++;
            }
        }
        vis[n-1]=false;
        cout<<forwardjump<<" ";
        int taken=false;
        int prev;
        for(i=0;i<n;i++)
        {
            if(!vis[i] && taken==false)
            {
                prev=stones[i];
                taken=true;
            }
            else if(!vis[i])
            {
                forwardjump=max(forwardjump,stones[i]-prev);
                prev=stones[i];
            }
        }
        return forwardjump;
    }
};