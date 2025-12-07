class Solution {
public:

    bool isprime(string s)
    {
        if(s=="1")
        {
            return false;
        }
        int temp=stoi(s);
        for(int i=2;i*i<=temp;i++)
        {
            if(temp%i==0)
            {
                return false;
            }
        }
        return true;
    }

    bool completePrime(int num) {
        if(num==1)
        {
            return false;
        }
        string s=to_string(num);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            string prefix=s.substr(0,i+1);
            string suffix=s.substr(i);
            if(!isprime(prefix) || !isprime(suffix))
            {
                return false;
            }
        }
        return true;
    }
};