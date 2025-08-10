class Solution {
public:

    string sorted(int s)
    {
        string temp=to_string(s);
        sort(temp.begin(),temp.end());
        return temp;
    } 

    bool reorderedPowerOf2(int n) {
        string s = sorted(n); 
        for (long long temp = 1; temp <= INT_MAX; temp <<= 1) {
            if (sorted(temp) == s) return true;
        }
        return false;
    }
};