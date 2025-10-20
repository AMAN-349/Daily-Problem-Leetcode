class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        string temp1="++X";
        string temp2="X++";
        int c1=0,c2=0;
        for(auto i:operations)
        {
            if(i==temp1 || i==temp2)
            {
                c1++;
            }
            else{
                c2++;
            }
        }
        return c1-c2;
    }
};