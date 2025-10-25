class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int res=0;
        int result=0;
        for(int i=1;i<=n;i++)
        {
            if(i%7==1)
            {
                ans++;
                result+=ans;
                res=ans;
            }
            else{
                result+=(++res);
            }
        }
        return result;
    }
};