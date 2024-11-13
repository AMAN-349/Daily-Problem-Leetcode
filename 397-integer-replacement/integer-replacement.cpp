class Solution {
public:
    int integerReplacement(int n) {
      long long num=n;
       long long count=0;
        while(num>1)
        {
            if(num%2==0)
            {
                num=num/2;
                
            }
            else
            {
                 if (num == 3 || (num & 2) == 0)
                   num=num-1;
                else
                   num=num+1;
               
               

            }
             count++;
        }
        return count;
    }
};