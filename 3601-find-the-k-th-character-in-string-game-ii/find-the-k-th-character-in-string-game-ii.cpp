class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int index=0;
        long len=1;
        for(int i=0;i<operations.size();i++)
        {
            len*=2;
            if(len>=k)
            {
                index=i;
                break;
            }
        }
        int shift=0;
        for(int j=index;j>=0;j--)
        {
            len/=2;
            if(k>len)
            {
                if(operations[j]==1)
                {
                    shift++;
                }
                k=k-len;
            }
        }
        return char('a'+(shift%26));
    }
};