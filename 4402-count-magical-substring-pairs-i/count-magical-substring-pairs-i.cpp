class Solution {
public:
    int countMagicalPairs(string s) {
        int n=s.size();
        vector<unordered_map<int,int>> v(n);

        for(int i=0;i<n;i++)
        {
            unordered_set<int> st;
            unordered_map<int,int> temp;
            for(int j=i;j<n;j++)
            {
                st.insert(s[j]);
                temp[st.size()]++;
            }
            v[i]=temp;
        }
        int ans=0;

        for(int i=0;i<n;i++)
        {
            unordered_set<int> temp;
            for(int j=i;j<n-1;j++)
            {
                temp.insert(s[j]);
                if(v[j+1].find(temp.size())!=v[j+1].end())
                {
                    ans+=v[j+1][temp.size()];
                }
            }
        }
        return ans;
    }
};