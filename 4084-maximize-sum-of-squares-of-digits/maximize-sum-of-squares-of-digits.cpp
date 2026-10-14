class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>num*9) return "";
        int temp=sum;
        string ans="";
        for(int i=1;i<=num;i++)
            {
                int mid=min(temp,9);
                ans+=(mid+'0');
                temp-=mid;
            }
        return ans;
    }
};