class Solution {
public:

    bool issorted(vector<string> s)
    {
        for(int i=1;i<s.size();i++)
        {
            if(s[i]<s[i-1])
            {
                return false;
            }
        }
        return true;
    }

    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        vector<string> temp(n);
        int ans=0;
        for(int i=0;i<m;i++)
        {
            vector<string> temp2=temp;
            for(int j=0;j<n;j++)
            {
                temp2[j]+=strs[j][i];
            }
            if(issorted(temp2))
            {
                temp=temp2;
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};