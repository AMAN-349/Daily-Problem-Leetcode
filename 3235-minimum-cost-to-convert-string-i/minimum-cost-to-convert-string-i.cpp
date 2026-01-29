class Solution {
public:

    void shortest_distance(vector<vector<long long>>& dist)
    {
        for(int k=0;k<26;k++)
        {
            for(int i=0;i<26;i++)
            {
                for(int j=0;j<26;j++)
                {
                    if(dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
                        dist[i][j]=min(1LL*dist[i][j],1LL*dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> dist(26,vector<long long>(26,LLONG_MAX));
        for(int i = 0; i < 26; i++) {
            dist[i][i] = 0;
        }
        int n=original.size();
        for(int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        shortest_distance(dist);

        long long ans=0;
        for(int i=0;i<source.size();i++)
        {
            if(source[i]!=target[i])
            {
                if(dist[source[i]-'a'][target[i]-'a']==LLONG_MAX)
                {
                    return -1;
                }
                ans+=dist[source[i]-'a'][target[i]-'a'];
            }
        }
        return ans;
    }
};