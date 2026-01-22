class Solution {
public:

    int find(int n)
    {
        int cnt=0;
        int temp=n;
        while(temp & 1)
        {
            temp>>=1;
            cnt++;
        }
        int temp2=(1<<(cnt-1));
        return n^temp2;
    }

    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                ans.push_back(-1);
            }
            else{
                int temp=find(nums[i]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};