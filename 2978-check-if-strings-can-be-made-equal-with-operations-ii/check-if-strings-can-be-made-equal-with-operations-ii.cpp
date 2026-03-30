class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.size();
        string p1="";
        string p2="";
        string p3="";
        string p4="";

        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                p1+=s1[i];
                p3+=s2[i];
            }
            else{
                p2+=s1[i];
                p4+=s2[i];
            }
        }
        sort(p1.begin(),p1.end());
        sort(p2.begin(),p2.end());
        sort(p3.begin(),p3.end());
        sort(p4.begin(),p4.end());

        return p1==p3 && p2==p4;
        
    }
};