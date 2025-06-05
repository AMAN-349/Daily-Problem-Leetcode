class Solution {
public:

    vector<double> find2(double a,double b)
    {
        vector<double> ans;
        ans.push_back(a+b);
        ans.push_back(a-b);
        ans.push_back(b-a);
        ans.push_back(a*b);
        if(abs(b)>FLT_EPSILON)
        {
            ans.push_back(a/b);
        }
        if(abs(a)>FLT_EPSILON)
        {
            ans.push_back(b/a);
        }
        return ans;
    }

    bool find(vector<double> v)
    {
        int n=(int) v.size();
        if(n==1)
        {
            return abs(24-v[0])<=FLT_EPSILON;
        }
        for(int f=0;f<n;f++)
        {
            for(int s=0;s<n;s++)
            {
                if(s==f) continue;
                double first=v[f];
                double second=v[s];
                vector<double> valid=find2(first,second);
                vector<double> nextarr;
                for(double d:valid)
                {
                    nextarr.clear();
                    nextarr.push_back(d);
                    for(int i=0;i<n;i++)
                    {
                        if(i==f || i==s)
                        {
                            continue;
                        }
                        nextarr.push_back(v[i]);
                    }
                    if(find(nextarr)) return true;
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> v(cards.begin(),cards.end());
        return find(v);
    }
};