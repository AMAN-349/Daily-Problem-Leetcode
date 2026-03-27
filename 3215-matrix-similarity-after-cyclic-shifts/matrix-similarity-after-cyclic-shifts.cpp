class Solution {
public:

    void shiftleft(vector<int>& v)
    {
        int temp=v[0];
        int i=0;
        for(i=1;i<v.size();i++)
        {
            v[i-1]=v[i];
        }
        v[i-1]=temp;
    }

    void shiftright(vector<int>& v)
    {
        int temp=v[v.size()-1];
        for(int i=v.size()-2;i>=0;i--)
        {
            v[i+1]=v[i];
        }
        v[0]=temp;
    }

    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> org=mat;
        int n=mat.size();
        int m=mat[0].size();

        k=(k%m);

        while(k--)
        {
            for(int i=0;i<n;i++)
            {
                if(i%2==0)
                {
                    shiftleft(mat[i]);
                }
                else
                {
                    shiftright(mat[i]);
                }
            }
        }

        return mat==org;

    }
};