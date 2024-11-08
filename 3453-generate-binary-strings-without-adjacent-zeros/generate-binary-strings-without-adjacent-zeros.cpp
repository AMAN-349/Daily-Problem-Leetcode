class Solution {
public:

    void find(int n,string temp,vector<string>& ans)
    {
        if(n==temp.size())
        {
            ans.push_back(temp);
            return;
        }
        if(temp.back()=='0')
        {
            find(n,temp+"1",ans);
        }
        else{
            find(n,temp+"0",ans);
            find(n,temp+"1",ans);
        }
    }

    vector<string> validStrings(int n) {
        string temp="";
        vector<string> ans;
        find(n,temp+"0",ans);
        find(n,temp+"1",ans);
        return ans;

    }
};
// 0
// 1

// 01
// 10
// 11

// 010
// 011

// 101

// 111
// 110