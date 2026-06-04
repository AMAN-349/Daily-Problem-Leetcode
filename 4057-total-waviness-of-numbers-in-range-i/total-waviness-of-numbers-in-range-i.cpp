class Solution {
public:

    int find(int i)
    {
        vector<int> v;
        int ans=0;
        while(i>0)
            {
                v.push_back(i%10);
                i=i/10;
            }
        for(int i=1;i<v.size()-1;i++)
            {
                if((v[i]>v[i-1] && v[i]>v[i+1]) || (v[i]<v[i-1] && v[i]<v[i+1]))
                {
                    ans++;
                }
            }
        return ans;
    }
    
    int totalWaviness(int num1, int num2) {
        int range=num2-num1+1;
        int ans=0;
        for(int i=num1;i<=num2;i++)
            {
                ans+=find(i);
            }
        return ans;
    }
};