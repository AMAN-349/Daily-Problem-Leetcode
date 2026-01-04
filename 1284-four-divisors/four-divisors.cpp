class Solution {
public:

    void find(int i,int& sum)
    {
        int temp=0;
        int cnt=0;
        for(int j=1;j*j<=i;j++)
        {
            if(i%j==0)
            {
                if(j*j==i)
                {
                    temp+=j;
                    cnt++;
                }
                else{
                    temp+=j;
                    temp+=i/j;
                    cnt+=2;
                }
            }
        }
        cout<<cnt<<" ";
        if(cnt==4)
        {
            sum+=temp;
        }
    }

    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto i:nums)
        {
            find(i,sum);
        }
        return sum;
    }
};