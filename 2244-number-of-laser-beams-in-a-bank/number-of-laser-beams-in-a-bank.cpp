class Solution {
public:

    int cnt(string bank)
    {
        int ans=0;
        for(auto i:bank)
        {
            if(i=='1')
            {
                ans++;
            }
        }
        return ans;
    }

    int numberOfBeams(vector<string>& bank) {
        int temp=cnt(bank[0]);
        int ans=0;
        for(int i=1;i<bank.size();i++)
        {
            int temp2=cnt(bank[i]);
            if(temp2>0){
                ans+=temp*temp2;
                temp=temp2;
            }
        }
        return ans;
    }
};