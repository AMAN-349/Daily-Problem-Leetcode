struct Trie {
    Trie* child[26];
    int id;

    Trie() {
        for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }
        id = -1;
    }
};

int add(Trie* node, const string& word,int& index)
{
    for(char ch:word)
    {
        int i=ch-'a';
        if(!node->child[i])
        {
            node->child[i]=new Trie();
        }
        node=node->child[i];
    }
    if(node->id==-1)
    {
        node->id=++index;
    }
    return node->id;
}

class Solution {
public:

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n=source.size();
        int m=original.size();
        Trie* root=new Trie();
        vector<vector<int>> v(2*m,vector<int>(2*m,INT_MAX));
        for(int i=0;i<m;i++)
        {
            v[i][i]=0;
        }
        int p=-1;
        for(int i=0;i<m;i++)
        {
            int hash1=add(root,original[i],p);
            int hash2=add(root,changed[i],p);
            v[hash1][hash2]=min(v[hash1][hash2],cost[i]);
        }

        for(int k=0;k<=p;k++)
        {
            for(int i=0;i<=p;i++)
            {
                for(int j=0;j<=p;j++)
                {
                    if(v[i][k]!=INT_MAX && v[k][j]!=INT_MAX)
                    v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
                }
            }
        }

        vector<long long> f(n,-1);
        for(int j=0;j<n;j++)
        {
            if(j>0 && f[j-1]==-1)
            {
                continue;
            }
            long long temp=(j==0)?0:f[j-1];
            if(source[j]==target[j])
            {
                if(f[j]==-1 || temp<f[j])
                {
                    f[j]=temp;
                }
            }
            Trie* u=root;
            Trie* u2=root;
            for(int i=j;i<n;i++)
            {
                u=u->child[source[i]-'a'];
                u2=u2->child[target[i]-'a'];

                if(!u || !u2)
                {
                    break;
                }

                if(u->id!=-1 && u2->id!=-1 && v[u->id][u2->id]!=INT_MAX)
                {
                    if(f[i]==-1 || temp+v[u->id][u2->id]<f[i])
                    {
                        f[i]=temp+v[u->id][u2->id];
                    }
                }
            }
        }
        return f[n-1];

    }
};