class Solution {
public:

    void find(string temp,int n,int& k,string& ans)
    {
        if(temp.size()==n)
        {
            cout<<temp<<" ";
            k--;
            if(k==0)
            {
                ans=temp;
            }
            return;
        }
        if(temp=="" || temp[temp.size()-1]!='a')
        {
            temp+="a";
            find(temp,n,k,ans);
            temp.pop_back();
        }
        if(temp=="" || temp[temp.size()-1]!='b')
        {
            temp+="b";
            find(temp,n,k,ans);
            temp.pop_back();
        }
        if(temp=="" || temp[temp.size()-1]!='c')
        {
            temp+="c";
            find(temp,n,k,ans);
            temp.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string temp="";
        string ans;
        find(temp,n,k,ans);
        return ans;
    }
};