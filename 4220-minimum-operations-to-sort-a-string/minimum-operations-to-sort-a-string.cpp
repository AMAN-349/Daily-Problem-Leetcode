class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        string temp=s;
        sort(temp.begin(),temp.end());
        if(s==temp) return 0;
        if(s[0]==temp[0]) return 1;
        if(s[n-1]==temp[n-1]) return 1;
        if(s[n-1]==temp[0] && s[0]==temp[n-1] && n==2) return -1;

        char mini=temp[0];
        char maxi=temp[n-1];

        int idx1=s.find(mini);
        int idx2=s.rfind(maxi);

        cout<<idx1<<" "<<idx2;

        if(idx2>idx1 || idx1!=n-1 || idx2!=0) return 2;
        if(idx1-idx2==1) return 2;
        return 3;
    }
};