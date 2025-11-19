class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans=nums;
        if(ans[n-1]<9)
        {
            ans[n-1]+=1;
            return ans;
        }
        int i=n-1;
        int carry=0;
        while(i>=0)
            {
                if(ans[i]<9)
                {
                    ans[i]+=1;
                    return ans;
                }
                ans[i]=0;
                i--;
            }
        ans.insert(ans.begin(),1);
        return ans;
    }
};