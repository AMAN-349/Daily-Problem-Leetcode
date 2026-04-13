class Solution {
public:

    unordered_map<string, int> dp;

    int finddiff(pair<int,int>& a1,pair<int,int>& b1)
    {
        return abs(a1.first-b1.first)+abs(b1.second-a1.second);
    }

    int find(int i,string& word,char first,char second,int ans,unordered_map<char,pair<int,int>>& m)
    {
        if(i==word.size())
        {
            return 0;
        }

        string key = to_string(i) + "#" + first + second;

        if(dp.find(key)!=dp.end())
        {
            return dp[key];
        }

        //choice 1
        int temp=INT_MAX;
        if(first==' ' || word[i]==first)
        {
            temp=min(temp,ans+find(i+1,word,word[i],second,ans,m));
        }
        else{
            int res=finddiff(m[word[i]],m[first]);
            temp=min(temp,res+ans+find(i+1,word,word[i],second,ans,m));
        }

        //choice 2

        if(second==' ' || word[i]==second)
        {
            temp=min(temp,ans+find(i+1,word,first,word[i],ans,m));
        }
        else{
            int res=finddiff(m[word[i]],m[second]);
            temp=min(temp,res+ans+find(i+1,word,first,word[i],ans,m));
        }

        return dp[key]=temp;
    }

    int minimumDistance(string word) {
        unordered_map<char,pair<int,int>> m;
        char ch='A';
        int i=0;
        int j=0;
        while(i<5)
        {
            while(j<6 && ch<='Z')
            {
                m[ch]={i,j};
                j++;
                ch++;
            }
            i++;
            j=0;
        }
        return find(0,word,' ',' ',0,m);
    }
};