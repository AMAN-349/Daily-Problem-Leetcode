struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int key, int val) : key(key) , val(val) , prev(nullptr), next(nullptr){}
    };

class LRUCache {

public:
    int maxcap, currcap = 0;
    unordered_map<int, Node*> m;
    Node* head = nullptr;
    Node* tail = nullptr;

    LRUCache(int capacity) {
        maxcap = capacity;
    }

    void movetotail(Node* node, int val) {
        node->val = val;
        if (node == tail) return;
        if (head == tail) return;

        if (node == head) {
            head = head->next;
            head->prev = nullptr;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        node->prev = tail;
        node->next = nullptr;
        tail->next = node;
        tail = node;
    }

    void deletehead() {
        Node* temp = head;
        head = head->next;

        if (head) head->prev = nullptr;
        else tail = nullptr;

        delete temp;
        currcap--;
    }

    Node* addtotail(int key, int value) {
        Node* n = new Node(key, value);
        if (!tail) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
        currcap++;
        return n;
    }

    int get(int key) {
        if (!m.count(key)) return -1;
        Node* n = m[key];
        movetotail(n, n->val);
        return n->val;
    }

    void put(int key, int value) {
        if (m.count(key)) {
            movetotail(m[key], value);
            return;
        }

        if (currcap == maxcap) {
            m.erase(head->key);
            deletehead();
        }

        m[key] = addtotail(key, value);
    }
};
