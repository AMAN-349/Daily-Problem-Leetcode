class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        //diagonal of rectangle is sqrt(l^2 + b^2) //by pythagoras theorem
        float ans=0;
        int res=0;
        for(auto i:dimensions)
        {
            int l=i[0];
            int b=i[1];
            float temp=sqrt((l*l)+(b*b));
            cout<<temp<<" ";
            if(temp==ans)
            {
                res=max(res,l*b);
            }
            if(temp>ans)
            {
                ans=temp;
                res=l*b;
            }
        }
        return res;
    }
};