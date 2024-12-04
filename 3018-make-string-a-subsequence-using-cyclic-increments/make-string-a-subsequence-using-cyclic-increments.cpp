class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i=0;
        int j=0;
        int n=str1.size();
        int m=str2.size();
        while(i<n && j<m)
        {
            if(str1[i]==str2[j] || char('a' + (str1[i] - 'a' + 1) % 26)==str2[j])
            {
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(j==m) return true;
        return false;
    }
};