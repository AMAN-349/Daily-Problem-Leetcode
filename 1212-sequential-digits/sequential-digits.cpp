class Solution {
public:

    void find(int i,vector<int>& ans,int low,int high)
    {
        cout<<i<<" ";
        if(i>high)
        {
            return;
        }
        if(i>=low && i<=high)
        {
            ans.push_back(i);
        }
        if(i%10!=9)
        {
            find(i*10+(i%10+1),ans,low,high);
        }
    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1;i<=9;i++)
        {
            find(i,ans,low,high);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};