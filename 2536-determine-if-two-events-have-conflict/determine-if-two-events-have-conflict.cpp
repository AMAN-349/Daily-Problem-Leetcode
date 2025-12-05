class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        vector<int> v;
        vector<int> temp(2000,0);
        for(auto i:event1)
        {
            int ind=i.find(':');
            string s1=i.substr(0,ind);
            string s2=i.substr(ind+1);
            int pre=stoi(s1);
            int post=stoi(s2);
            float ans=pre*60+(post);
            v.push_back(ans);
        }
        int st=v[0];
        int end=v[1];
        for(int i=st;i<=end;i++)
        {
            temp[i]++;
        }
        for(auto i:event2)
        {
            int ind=i.find(':');
            string s1=i.substr(0,ind);
            string s2=i.substr(ind+1);
            int pre=stoi(s1);
            int post=stoi(s2);
            float ans=pre*60+(post);
            v.push_back(ans);
        }
        st=v[2];
        end=v[3];
        for(auto i:v)
        {
            cout<<i<<" ";
        }
        for(int i=st;i<=end;i++)
        {
            if(temp[i]==1)
            {
                return true;
            }
            temp[i]++;
        }
        return false;
    }
};