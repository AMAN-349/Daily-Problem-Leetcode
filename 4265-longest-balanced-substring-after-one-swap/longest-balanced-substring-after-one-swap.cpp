class Solution {
public:

    int find(string s)
    {
        int n=s.size();
        int ones=0,zeroes=0;
        for(auto i:s)
        {
            if(i=='1')
            {
                ones++;
            }
            else{
                zeroes++;
            }
        }
        int ans=0;
        int balance=0;
        unordered_map<int,int> m;
        m[0]=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                ones--;
                balance++;
            }
            else{
                zeroes--;
                balance--;
            }
            if(balance==0)
            {
                ans=max(ans,i+1);
                continue;
            }
            
            if(m.count(balance-2) && zeroes>0)
            {
                ans=max(ans,i-m[balance-2]);
            }
            if(m.count(balance+2) && ones>0)
            {
                ans=max(ans,i-m[balance+2]);
            }
            
            if(!m.count(balance))
            {
                m[balance]=i;
            }
        }
        return ans;
    }

    int longestBalanced(string s) {
        int n=s.size();
        string temp=s;
        reverse(temp.begin(),temp.end());
        return max(find(s),find(temp));
    }
};