class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;

        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                m1[nums1[i] + nums2[j]]++;
            }
        }

        for(int i = 0; i < nums3.size(); i++) {
            for(int j = 0; j < nums4.size(); j++) {
                m2[nums3[i] + nums4[j]]++;
            }
        }

        int ans = 0;
        for(auto i : m1) {
            int temp = -(i.first);
            if(m2.find(temp) != m2.end()) {
                ans += i.second * m2[temp];  
            }
        }

        return ans;
    }
};
