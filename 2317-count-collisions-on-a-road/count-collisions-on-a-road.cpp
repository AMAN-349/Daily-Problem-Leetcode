class Solution {
public:
    int countCollisions(string directions) {
        stack<char> s;
        int n=directions.size();
        int ans=0;
        int i=0;
        int j=n-1;
        while(i<n && directions[i]=='L')
        {
            i++;
        }
        while(j>=0 && directions[j]=='R')
        {
            j--;
        }
        for(int k=i;k<=j;k++)
        {
            if(directions[k]!='S')
            {
                ans++;
            }
        }
        return ans;
    }
};