class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;

        string temp(n,'.');

        ans.push_back(temp);

        for(int i=1;i<m;i++)
        {
            string temp="";
            for(int i=0;i<n;i++)
            {
                temp+='#';
            }
            temp[n-1]='.';

            ans.push_back(temp);
        }
        return ans;
    }
};