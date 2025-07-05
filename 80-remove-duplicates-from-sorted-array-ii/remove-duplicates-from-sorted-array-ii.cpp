class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> v;
        int i=0;
        int n=nums.size();
        int cnt=0;
        while(i<n)
        {
            int temp=nums[i];
            cnt=0;
            while(i<n && nums[i]==temp)
            {
                cnt++;
                i++;
            }
            if(cnt<2)
            {
                v.push_back(temp);
            }
            else{
                v.push_back(temp);
                v.push_back(temp);
            }
        }
        for(int i=0;i<v.size();i++)
        {
            nums[i]=v[i];
        }
        return v.size();
    }
};