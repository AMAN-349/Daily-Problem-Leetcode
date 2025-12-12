class Solution {
public:

    static bool cmp(vector<string> v1,vector<string> v2)
    {
        int a=stoi(v1[1]);
        int b=stoi(v2[1]);
        if(a==b)
        {
            return v1[0]=="OFFLINE";
        }
        return a<b;
    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(),events.end(),cmp);
        for(auto i:events)
        {
            cout<<i[1]<<" "<<i[2]<<" ";
        }
        set<int> onlines;
        for(int i=0;i<numberOfUsers;i++)
        {
            onlines.insert(i);
        }
        map<int,int> offlines;
        vector<int> ans(numberOfUsers, 0);
        int curr=0;
        for(auto i:events)
        {
            string event=i[0];
            int time=stoi(i[1]);
            string ids=i[2];
            if(event=="OFFLINE")
            {
                int id1=stoi(ids);
                if(onlines.find(id1)!=onlines.end())
                {
                    onlines.erase(id1);
                }
                offlines[id1]=time+60;
                continue;
            }
            for (auto it = offlines.begin(); it != offlines.end(); )
            {
                if (it->second <= time)
                {
                    onlines.insert(it->first);
                    it = offlines.erase(it);
                }
                else
                {
                    ++it;
                }
            }

            if(ids=="HERE")
            {
                for(auto i:onlines)
                {
                    ans[i]++;
                }
            }
            else if(ids=="ALL")
            {
                for(auto i:onlines)
                {
                    ans[i]++;
                }
                for(auto i:offlines)
                {
                    ans[i.first]++;
                }
            }
            else{
                string temp="";
                int res;
                for(auto i:ids)
                {
                    if(i==' ')
                    {
                        int j=0;
                        while(j < temp.size() && temp[j]>='a' && temp[j]<='z')
                        {
                            j++;
                        }
                        res=stoi(temp.substr(j));
                        ans[res]++;
                        temp="";
                    }
                    else{
                        temp+=i;
                    }
                }
                int j=0;
                while(j < temp.size() && temp[j]>='a' && temp[j]<='z')
                {
                    j++;
                }
                res=stoi(temp.substr(j));
                ans[res]++;
                temp="";

            }
        }
        return ans;
    }
};