class Solution {
public:
    int n;
    set<string> find(string& s,int& i)
    {
        set<string> result;
        set<string> curr={""};

        while(i<s.size() && s[i]!='}')
        {
            if(s[i]==',')
            {
                for(auto it:curr)
                {
                    result.insert(it);
                }
                i++;
                curr={""};
            }

            else if(s[i]=='{')
            {
                i++;
                set<string> temp=find(s,i);
                set<string> temp2;
                for(auto it : curr)
                {
                    for(auto it2 : temp)
                    {
                        temp2.insert(it + it2);
                    }
                }
                curr = temp2;
            }

            else{
                set<string> temp2;
                string ch=string(1,s[i]);
                for(auto it:curr)
                {
                    temp2.insert(it+ch);
                }
                curr=temp2;
                i++;
            }
        }
        for(auto it:curr)
        {
            result.insert(it);
        }

        if(i<n && s[i]=='}')
        {
            i++;
        }

        return result;


    }

    vector<string> braceExpansionII(string expression) {
        int i=0;
        n=expression.size();
        set<string> temp=find(expression,i);
        vector<string> ans(temp.begin(),temp.end());
        return ans;
    }
};