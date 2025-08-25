class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>> mp;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mp[i+j].push_back(mat[i][j]);
            }
        }
        bool flag=true;
        vector<int> ans;
        for(auto i:mp)
        {
            vector<int> temp=i.second;
            if(flag)
            {
                for(int i=temp.size()-1;i>=0;i--)
                {
                    ans.push_back(temp[i]);
                }
            }
            else{
                for(int i=0;i<temp.size();i++)
                {
                    ans.push_back(temp[i]);
                }
            }
            flag = !(flag);
        }
        return ans;
    }
};