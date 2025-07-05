class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> m;
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]]++;
        }
        int ans=-1;
        for(auto i:m)
        {
            if(i.first==i.second)
            {
                ans=i.first;
            }
        }
        return ans;
    }
};