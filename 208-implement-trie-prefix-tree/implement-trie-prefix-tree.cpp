struct Node{
    int data;
    Node* arr[26]={nullptr};
    bool end=false;

    Node(int data) : data(data){}
};

class Trie {
public:
    Node* root;
    Trie() {
        root=new Node(-1);
    }
    
    void insert(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(temp->arr[word[i]-'a']!=nullptr)
            {
                temp=temp->arr[word[i]-'a'];
            }
            else{
                temp->arr[word[i]-'a']=new Node(word[i]-'a');
                temp=temp->arr[word[i]-'a'];
            }
        }
        temp->end=true;
    }
    
    bool search(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(temp->arr[word[i]-'a']!=nullptr)
            {
                temp=temp->arr[word[i]-'a'];
            }
            else{
                return false;
            }
        }
        return temp->end==true;
    }
    
    bool startsWith(string prefix) {
        Node* temp=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(temp->arr[prefix[i]-'a']!=nullptr)
            {
                temp=temp->arr[prefix[i]-'a'];
            }
            else{
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */