class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        if(n==1) return true;
        if(bits[n-2]==0)
        {
            return true;
        }
        int i=0;
        for(i=0;i<=n-2;)
        {
            if(i<n-2 && bits[i]==1 && bits[i+1]==1)
            {
                i+=2;
            }
            else if(i<n-2 && bits[i]==1 && bits[i+1]==0)
            {
                i+=2;
            }
            else if(bits[i]==0)
            {
                i++;
            }
            else{
                break;
            }
            cout<<i<<" ";
        }
        cout<<i<<" ";
        return i==n-1;
        
    }
};