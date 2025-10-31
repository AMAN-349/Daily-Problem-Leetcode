class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> v;
        map<int,int> m;
        for(auto i:nums)
        {
            if(m[i]!=-1)
            m[i]++;
            if(m[i]>1)
            {
                v.push_back(i);
                m[i]=-1;
            }
        }
        return v;
    }
};