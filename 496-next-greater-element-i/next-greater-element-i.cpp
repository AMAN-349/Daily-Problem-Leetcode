class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            auto it=find(nums2.begin(),nums2.end(),nums1[i]);
            int flag=0;
            for(auto i=it+1;i<nums2.end();i++)
            {
                if(*i>*it)
                {
                    ans.push_back(*i);
                    flag=1;
                    break;
                }
            }
            if(!flag)
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};