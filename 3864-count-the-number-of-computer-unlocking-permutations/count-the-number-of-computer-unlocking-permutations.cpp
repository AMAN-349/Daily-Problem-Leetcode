class Solution {
public:

    long long mod=1e9+7;

    long long fact(int n)
    {
        if(n==0)
        {
            return 1;
        }
        return (1LL*n*fact(n-1))%mod;
    }

    int countPermutations(vector<int>& complexity) {
        int n=complexity.size();
        map<int,int> m;
        for(auto i:complexity)
        {
            m[i]++;
        }
        int ind=min_element(complexity.begin(),complexity.end())-complexity.begin();
        int mini=complexity[ind];
        if(m[mini]>1 || ind!=0)
        {
            return 0;
        }
        return fact(n-1);
    }
};