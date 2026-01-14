class Solution {
public:

    void find(string& temp,int open,int closed,vector<string>& ans)
    {
        if(open==0 && closed==0)
        {
            cout<<"h";
            ans.push_back(temp);
            return;
        }
        if(open==closed)
        {
            temp+="(";
            find(temp,open-1,closed,ans);
            temp.pop_back();
        }
        if(open<closed)
        {
            if(open>0)
            {
                temp+="(";
                find(temp,open-1,closed,ans);
                temp.pop_back();
            }
            if(closed>0)
            {
                temp+=")";
                find(temp,open,closed-1,ans);
                temp.pop_back();
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp="";
        find(temp,n,n,ans);
        return ans;
    }
};