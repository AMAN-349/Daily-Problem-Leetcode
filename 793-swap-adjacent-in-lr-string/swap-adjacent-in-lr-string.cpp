class Solution {
public:
    bool canTransform(string start, string result) {
        int n=start.size();
        int i=0;
        int j=0;
        int cntr=0;
        int cntl=0;
        for(auto i:start)
        {
            if(i=='L')
            {
                cntl++;
            }
            if(i=='R'){
                cntr++;
            }
        }
        for(auto i:result)
        {
            if(i=='L')
            {
                cntl--;
            }
            if(i=='R'){
                cntr--;
            }
        }
        if(cntl!=0 || cntr!=0) return false;
        while(i<n && j<n)
        {
            while(start[i]=='X')
            {
                i++;
            }
            while(result[j]=='X')
            {
                j++;
            }
            if(start[i]!=result[j])
            {
                return false;
            }
            else{
                if(start[i]=='L'){
                    if(i<j) return false;
                }
                else{
                    if(i>j) return false;
                }
            }
            i++;
            j++;
        }
        return true;
    }
};