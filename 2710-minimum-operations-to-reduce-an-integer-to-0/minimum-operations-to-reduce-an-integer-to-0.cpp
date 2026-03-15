class Solution {
public:
    vector<int> v;

    int find(int n,vector<int>& v)
    {
        auto it=lower_bound(v.begin(),v.end(),n);
        if(*it==n)
        {
            return 1;
        }
        int temp1=*(--it);
        int temp2=*upper_bound(v.begin(),v.end(),n);

        int diff1=temp2-n;
        int diff2=n-temp1;

        return 1+min(find(diff1,v),find(diff2,v));

    }

    int minOperations(int n) {
        for(int i=0;i<31;i++)
        {
            v.push_back(pow(2,i));
        }

        return find(n,v);
    }
};