class Solution {
public:
    int n;
    vector<int> ans;

    bool check(vector<int>& v1, vector<int>& v2)
    {
        int n = v1.size();

        vector<int> temp = v1;
        temp.insert(temp.end(), v1.begin(), v1.end());

        vector<int> lps(n, 0);
        for(int i = 1, len = 0; i < n; )
        {
            if(v2[i] == v2[len])
                lps[i++] = ++len;
            else if(len)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }

        for(int i = 0, j = 0; i < 2*n; )
        {
            if(temp[i] == v2[j])
            {
                i++; j++;
                if(j == n) return true;
            }
            else if(j)
                j = lps[j - 1];
            else
                i++;
        }

        return false;
    }

    bool isValid(int grp, vector<int>& nums)
    {
        int i=0;
        while(i<n)
        {
            vector<int> v1(nums.begin()+i, nums.begin()+i+grp);
            vector<int> v2(ans.begin()+i, ans.begin()+i+grp);

            if(!check(v1,v2))
            {
                return false;
            }

            i+=grp;
        }

        return true;

    }

    int sortableIntegers(vector<int>& nums) {
        n=nums.size();
        ans=nums;
        sort(ans.begin(),ans.end());
        int cnt=0;

        vector<int> divisors;

        for(int i = 1; i * i <= n; i++)
        {
            if(n % i == 0)
            {
                divisors.push_back(i);

                if(i != n / i)
                    divisors.push_back(n / i);
            }
        }


        for(auto i:divisors)
        {
            if(isValid(i,nums))
            {
                cnt+=i;
            }
        }
        return cnt;
    }
};