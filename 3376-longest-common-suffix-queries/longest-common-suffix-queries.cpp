class Trie {
public:

    struct Node {

        int next[26];
        pair<int,int> best;

        Node() {

            memset(next, -1, sizeof(next));

            best = {INT_MAX, INT_MAX};
        }
    };

    vector<Node> trie;

    Trie() {

        trie.push_back(Node()); // root node
    }

    void updateBest(int node, int ind, int len)
    {
        if(len < trie[node].best.second)
        {
            trie[node].best = {ind, len};
        }
        else if(len == trie[node].best.second &&
                ind < trie[node].best.first)
        {
            trie[node].best = {ind, len};
        }
    }

    void insert(string &word, int ind)
    {
        int node = 0;

        updateBest(node, ind, word.size());

        for(char ch : word)
        {
            int c = ch - 'a';

            if(trie[node].next[c] == -1)
            {
                trie[node].next[c] = trie.size();

                trie.push_back(Node());
            }

            node = trie[node].next[c];

            updateBest(node, ind, word.size());
        }
    }

    int query(string &word)
    {
        int node = 0;

        for(char ch : word)
        {
            int c = ch - 'a';

            if(trie[node].next[c] == -1)
            {
                break;
            }

            node = trie[node].next[c];
        }

        return trie[node].best.first;
    }
};

class Solution {
public:

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        Trie trie;

        for(int i = 0; i < wordsContainer.size(); i++)
        {
            reverse(wordsContainer[i].begin(),
                    wordsContainer[i].end());

            trie.insert(wordsContainer[i], i);
        }

        vector<int> ans;

        for(string &q : wordsQuery)
        {
            reverse(q.begin(), q.end());

            ans.push_back(trie.query(q));
        }

        return ans;
    }
};