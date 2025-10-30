class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        
        for(int i = 1; i <= n/2; i++) {
            if(num[0] == '0' && i > 1) break;
            long long a = stoll(num.substr(0, i));
            
            for(int j = 1; max(i, j) <= n - i - j; j++) {
                if(num[i] == '0' && j > 1) break;
                long long b = stoll(num.substr(i, j));

                int start = i + j;
                long long x = a, y = b, z = x + y;
                
                while(start < n) {
                    string s = to_string(z);
                    if(num.compare(start, s.size(), s) != 0) break;
                    
                    start += s.size();
                    x = y;
                    y = z;
                    z = x + y;
                }
                
                if(start == n) return true;
            }
        }
        return false;
    }
};
