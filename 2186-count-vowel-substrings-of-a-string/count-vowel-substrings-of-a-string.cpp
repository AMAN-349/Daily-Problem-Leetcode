class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.size();
        if (n < 5) {
            return 0;
        }
        
        int vowelSubstringCount = 0;
        for (int start = 0; start < n - 4; start++) {
        
            int cntA = 0, cntE = 0, cntI = 0, cntO = 0, cntU = 0;
            
            
            for (int end = start; end < n; end++) {
                char ch = word[end];
                if (ch == 'a') cntA++;
                else if (ch == 'e') cntE++;
                else if (ch == 'i') cntI++;
                else if (ch == 'o') cntO++;
                else if (ch == 'u') cntU++;
                else break; 
                
                if (cntA > 0 && cntE > 0 && cntI > 0 && cntO > 0 && cntU > 0) {
                    vowelSubstringCount++;
                }
            }
        }
        
        return vowelSubstringCount;
    }
};
