class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
            {
                string s1=s.top();
                s.pop();
                string s2=s.top();
                s.pop();
                int a=stoi(s2);
                int b=stoi(s1);
                if(tokens[i]=="+")
                {
                    s.push(to_string(a+b));
                }
                else if(tokens[i]=="-")
                {
                    s.push(to_string(a-b));
                }
                else if(tokens[i]=="*")
                {
                    s.push(to_string(a*b));
                }
                else{
                    s.push(to_string(a/b));
                }
            }
            else{
                s.push(tokens[i]);
            }
        }
        int ans=stoi(s.top());
        return ans;
    }
};