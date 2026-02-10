class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
            {
                set<int> s1;
                set<int> s2;
                for(int j=i;j<n;j++)
                    {
                                if(nums[j]%2==0)
                                {
                                    s1.insert(nums[j]);
                                }
                                else{
                                    s2.insert(nums[j]);
                                }
                            
                        if(s1.size()==s2.size())
                        {
                            ans=max(ans,j-i+1);
                        }
                    }
            }
        return ans;
    }
};