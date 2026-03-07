class Solution {
public:
    int minFlips(string s) {
        int odd0=0;
        int odd1=0;
        int even0=0;
        int even1=0;
        int n=s.size();

        for(int i=0;i<s.size();i++)
        {
            if(i%2==0)
            {
                if(s[i]=='1')
                {
                    even1++;
                }
                else{
                    even0++;
                }
            }
            else{
                if(s[i]=='1')
                {
                    odd1++;
                }
                else{
                    odd0++;
                }
            }
        }
        int ans=min(odd1+even0,even1+odd0);
        if(n%2==0) return ans;
        cout<<even1<<" "<<even0;
        cout<<endl;
        cout<<odd1<<" "<<odd0;
        cout<<endl;
        cout<<"----";
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            int temp=s[i]=='1'?1:0;
            swap(even1,odd1);
            swap(odd0,even0);
            if(temp==1)
            {
                even1++;
                odd1--;
            }
            else{
                even0++;
                odd0--;
            }
            ans=min(ans,min(odd1+even0,even1+odd0));
        }

        return ans;
    }
};