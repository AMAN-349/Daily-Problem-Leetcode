class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n=boxGrid.size();
        int m=boxGrid[0].size();
        vector<vector<char>> ans;

        for(int i=0;i<n;i++)
        {
            int cnt=0;
            vector<char> temp(m,'.');
            for(int j=0;j<m;j++)
            {
                if(boxGrid[i][j]=='*')
                {
                    temp[j]='*';
                    int pos=j-1;
                    while(pos>=0 && cnt>0)
                    {
                        temp[pos--]='#';
                        cnt--;
                    }
                    cnt=0;
                }
                else if(boxGrid[i][j]=='#' || j==m-1)
                {
                    if(boxGrid[i][j]=='#')
                    cnt++;
                    if(j==m-1)
                    {
                        int pos=j;
                        while(pos>=0 && cnt>0)
                        {
                            if(temp[j]=='*')
                            {
                                break;
                            }
                            temp[pos--]='#';
                            cnt--;
                        }
                        cnt=0;
                    }
                }
            }
            ans.push_back(temp);
        }
        vector<vector<char>> res;
        for(int i=0;i<m;i++)
        {
            vector<char> temp;
            for(int j=n-1;j>=0;j--)
            {
                temp.push_back(ans[j][i]);
            }
            res.push_back(temp);
        }
        return res;
    }
};