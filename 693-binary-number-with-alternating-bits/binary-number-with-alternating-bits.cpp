class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int> v;
        while(n>0)
        {
            v.push_back(n%2);
            n=n/2;
        }
        if(v.size()<=1) return true;
        int curr=v[0];
        for(int i=1;i<v.size();i++)
        {
            if(v[i]==curr) return false;
            curr=v[i];
        }
        return true;
    }
};