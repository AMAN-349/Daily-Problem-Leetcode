class Solution {
public:
    int kthGrammar(int n, int k) {
        int curr=0;
        int l=1;
        int r=pow(2,n-1);
        int m;
        while(l!=r)
        {
            m=(l+r)/2;
            if(k<=m)
            {
                r=m;
            }
            else{
                l=m+1;
                curr=1-curr;
            }
        }
        return curr;

        
    }
};