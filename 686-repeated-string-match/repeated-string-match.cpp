class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int cnt=1;
        int n=a.size();
        string temp=a;
        int m=b.size();
        if(a.find(b)!=string::npos)
        {
            return cnt;
        }
        while(a.size()<m)
        {
            a+=temp;
            cnt++;
        }
        cout<<a<<" ";
        if(a.find(b)!=string::npos)
        {
            return cnt;
        }
        a+=temp;
        if(a.find(b)!=string::npos)
        {
            return cnt+1;
        }
        return -1;
    }
};