class Solution {
public:
    int smallestRepunitDivByK(int k) {
        vector<int> ans;
        ans.push_back(0);
        long long temp=1;
        int mod=temp%k;
        if(mod==0)
        {
            return 1;
        }
        int t=k;
        while(t--)
        {
            mod=((mod*10)+1)%k;
            cout<<mod<<" ";
            if(mod==0)
            {
                return ans.size()+1;
            }
            if(mod==ans.back())
            {
                return -1;
            }
            ans.push_back(mod);
        }
        if(ans.back()==0)
        return ans.size();
        return -1;
    }
};