class Solution {
public:

    void rightrotate(int i,int j,vector<int>& temp) {
        int num = temp[j];
        for(int k = j-1; k >= i; k--) temp[k+1] = temp[k];
        temp[i] = num;
    }

    void leftrotate(int i,int j,vector<int>& temp) {
        int num = temp[i];
        for(int k = i+1; k <= j; k++) temp[k-1] = temp[k];
        temp[j] = num;
    }

    void find(int i,int n,vector<int>& temp,vector<vector<int>>& ans)
    {
        if(i==n-1)
        {
            ans.push_back(temp);
            return;
        }
        unordered_map<char,int> m;
        for(int j=i;j<n;j++)
        {
            if(m[temp[j]]==0){
                //right rotate
                rightrotate(i,j,temp);
                find(i+1,n,temp,ans);
                //left rotate
                leftrotate(i,j,temp);
                m[temp[j]]++;
            }
            //m[temp[j]]++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        find(0,n,nums,ans);
        return ans;
    }
};