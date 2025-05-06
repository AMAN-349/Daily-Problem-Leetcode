class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //here we use boyer moore's voting algorithm
        int n=nums.size();
        int elem1=INT_MIN;
        int elem2=INT_MIN;
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(cnt1==0 && nums[i]!=elem2)
            {
                elem1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0 && nums[i]!=elem1)
            {
                elem2=nums[i];
                cnt2=1;
            }
            else if(elem1==nums[i])
            {
                cnt1++;
            }
            else if(elem2==nums[i])
            {
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==elem1)
            {
                cnt1++;
            }
            if(nums[i]==elem2)
            {
                cnt2++;
            }
        }
        vector<int> res;
        int find=floor(n/3);
        if(cnt1>find) res.push_back(elem1);
        if(cnt2>find) res.push_back(elem2);
        sort(res.begin(),res.end());
        return res;
    }
};