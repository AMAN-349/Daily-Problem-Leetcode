class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n=answers.size();
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[answers[i]]++;
        }
        int ans=0;
        for(auto i:m)
        {
            int size=i.first+1;
            int cnt=ceil((double)i.second/size);
            ans+=size*cnt;
        }
        return ans;
    }
};