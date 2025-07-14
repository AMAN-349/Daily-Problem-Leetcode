class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int l = 0;              // ← you never really need l, but I’ll keep it
        int r = n - 1;
        int ans = 0;

        while (s.size() != 1) {
            if (s[r] == '0') {          
                s.pop_back();           
                r--;
            }
            else {
                int carry = 0;

                for (int j = r; j >= l; ) {
                    if (s[j] == '1') {  
                        s[j] = '0';     
                        carry = 1;
                        j--;           
                    } else {
                        s[j] = '1';
                        carry = 0;
                        j--;           
                        break;
                    }
                }

                if (carry == 1) {
                    s = '1' + s;        
                    r++;               
                }
            }

            ans++;
        }

        return ans;
    }
};
