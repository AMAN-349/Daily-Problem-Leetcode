class Solution {
public:
    string addBinary(string a, string b) {
        string result="";
        int n=a.size()-1;
        int m=b.size()-1;
        int temp=0;
        while(n>=0 || m>=0 || temp==1)
        {
            temp+=(n>=0)?a[n]-'0':0;
            temp+=(m>=0)?b[m]-'0':0;
            result=char(temp%2+'0')+result;
            temp=temp/2;
            n--;
            m--;
        }
        return result;
    }
};