class Solution {
public:

    int compid=0;

    void find(int station, vector<vector<int>>& con, vector<int>& vis,set<int>& ans,vector<int>& components)
    {
        components[station]=compid;
        vis[station]=1;
        ans.insert(station);
        for (auto i : con[station])
        {
            if(!vis[i])
            {
                find(i,con,vis,ans,components);
            }
        }
    }


    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> con(c+1);
        for(auto i:connections)
        {
            con[i[0]].push_back(i[1]);
            con[i[1]].push_back(i[0]);
        }
        vector<set<int>> child;
        vector<int> vis(c+1,0);
        vector<int> components(c+1);

        for(int i=1;i<=c;i++)
        {
            if(!vis[i])
            {
                set<int> temp;
                find(i,con,vis,temp,components);
                child.push_back(temp);
                compid++;
            }
        }
        for(auto i:child)
        {
            for(auto j:i)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
        for(auto i:components)
        {
            cout<<i<<" ";
        }



        vector<int> ans;

        for(auto i:queries)
        {
            int status=i[0];
            int station=i[1];
            int id=components[station];
            if(status==2)
            {
                child[id].erase(station);
            }
            else{
                if(child[id].find(station)!=child[id].end())
                {
                    ans.push_back(station);
                }
                else{
                    set<int>& temp=child[id];
                    if(temp.size()>0)
                    {
                        ans.push_back(*temp.begin());
                    }
                    else{
                        ans.push_back(-1);
                    }
                }
            }
        }
        return ans;

    }
};