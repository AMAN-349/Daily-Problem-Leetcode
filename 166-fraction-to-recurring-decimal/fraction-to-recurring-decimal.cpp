#include <string>
#include <map>

class Solution {
public:
    std::string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }

        std::string ans = "";
        if ((numerator < 0) ^ (denominator < 0)) {
            ans += "-";
        }

        long long num = std::abs(static_cast<long long>(numerator));
        long long den = std::abs(static_cast<long long>(denominator));

        long long q = num / den;
        long long r = num % den;
        ans += std::to_string(q);

        if (r == 0) {
            return ans;
        } else {
            ans += '.';
            std::map<long long, int> m;

            while (r != 0) {
                if (m.find(r) != m.end()) {
                    int temp = m[r];
                    ans.insert(temp, "(");
                    ans += ')';
                    break;
                } else {
                    m[r] = ans.size();
                    r = r * 10;
                    q = r / den;
                    r = r % den;
                    ans += std::to_string(q);
                }
            }

            return ans;
        }
    }
};