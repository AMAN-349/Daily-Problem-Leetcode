class TreeAncestor {
public:
    vector<vector<int>> nodes;
    int rows=17;

    void build(vector<int>& parent,int n)
    {
        for(int i=0;i<n;i++)
        {
            nodes[0][i]=parent[i];
        }
        for(int i=1;i<rows;i++)
        {
            for(int j=0;j<n;j++)
            {
                if (nodes[i-1][j] == -1)
                    nodes[i][j]=-1;
                else
                    nodes[i][j]=nodes[i-1][nodes[i-1][j]];
            }
        }
    }

    TreeAncestor(int n, vector<int>& parent) {
        nodes.resize(17,vector<int>(n,0));
        build(parent,n);
    }
    
    int getKthAncestor(int node, int k) {
        int u=node;
        for(int i=0;i<rows;i++)
        {
            int mask=(1<<i);
            if(k&mask)
            {
                if(nodes[i][u]==-1) return -1;
                u=nodes[i][u];
            }
        }
        return u;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */