class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal) return true;
        int n=s.size();
        string temp=s;
        reverse(temp.begin(),temp.end());
        if(temp==goal)
        {
            return true;
        }
        for(int i=1;i<n;i++)
        {
            char t=goal[0];
            for(int i=1;i<n;i++)
            {
                goal[i-1]=goal[i];
            }
            goal[n-1]=t;
            if(s==goal)
            {
                return true;
            }
        }
        return false;
    }
};