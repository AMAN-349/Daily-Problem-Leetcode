class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> sorted_nums;
        for(int i = 0; i < n; i++) {
            sorted_nums.push_back({nums[i], i});
        }
        sort(sorted_nums.begin(), sorted_nums.end());

        int i = 0;
        while (i < n) {
            int j = i + 1;
            
            while (j < n && sorted_nums[j].first - sorted_nums[j-1].first <= limit) {
                j++;
            }
            vector<int> indices;
            for (int k = i; k < j; k++) {
                indices.push_back(sorted_nums[k].second);
            }
            sort(indices.begin(), indices.end());
            for (int k = 0; k < indices.size(); k++) {
                nums[indices[k]] = sorted_nums[i + k].first;
            }
            i = j; 
        }

        return nums;
    }
};