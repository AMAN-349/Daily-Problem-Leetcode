class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> v(10001,0);
        for(auto i:trips)
        {
            int cap=i[0];
            int st=i[1];
            int end=i[2];
            v[st]+=cap;
            v[end]-=cap;
        }
        int sum=0;
        for(auto &i:v)
        {
            sum=sum+i;
            if(sum>capacity)
            {
                return false;
            }
        }
        return true;
    }
};