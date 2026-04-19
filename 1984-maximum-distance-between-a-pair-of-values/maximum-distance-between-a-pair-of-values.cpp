class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        int i=n1-1;
        int j=n2-1;
        int ans=0;

        while(i>=0 && j>=0)
        {
            while(j>=0 && nums2[j]<nums1[i])
            {
                j--;
            }
            ans=max(ans,j-i);
            i--;
        }
        return ans;


    }
};