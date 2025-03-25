class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> nums(words.size());
        
        for (int i = 0; i < words.size(); i++) {
            int temp = 0;
            for (char ch : words[i]) {
                temp |= (1 << (ch - 'a')); 
            }
            nums[i] = temp;
        }

        int ans = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {  
                if ((nums[i] & nums[j]) == 0) {  
                    ans = max(ans, (int)(words[i].size() * words[j].size()));  
                }
            }
        }
        return ans;
    }
};
