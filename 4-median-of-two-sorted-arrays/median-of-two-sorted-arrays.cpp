class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n > m)
            return findMedianSortedArrays(nums2, nums1);

        int l = 0, r = n;
        int total = n + m;
        int half = (total + 1) / 2;

        while(l <= r) {
            int mid1 = (l + r) / 2;
            int mid2 = half - mid1;

            int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1-1];
            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2-1];
            int r1 = (mid1 == n) ? INT_MAX : nums1[mid1];
            int r2 = (mid2 == m) ? INT_MAX : nums2[mid2];

            if(l1 <= r2 && l2 <= r1) {
                if(total % 2 == 0)
                    return (double)(max(l1,l2) + min(r1,r2)) / 2;
                else
                    return max(l1,l2);
            } else if(l1 > r2) {
                r = mid1 - 1;
            } else {
                l = mid1 + 1;
            }
        }
        return 0;
    }
};
