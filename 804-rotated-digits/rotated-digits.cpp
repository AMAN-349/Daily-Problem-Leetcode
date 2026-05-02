class Solution {
public:

    bool isValid(int i)
    {
        int cnt1=0;
        int cnt2=0;
        bool flag=false;

        while(i>0)
        {
            int rem=i%10;
            if(rem==0 || rem==1 || rem==8)
            {
                cnt1++;
            }
            else if(rem==3 || rem==4 || rem==7)
            {
                return false;
            }
            cnt2++;
            i=i/10;
        }
        return cnt1!=cnt2;
    }

    int rotatedDigits(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(isValid(i))
            {
                cnt++;
            }
        }
        return cnt;
    }
};