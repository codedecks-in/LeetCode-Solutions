class LRUCache {
private:
    struct Node {
        Node *left = nullptr;
        Node *right = nullptr;
        
        int key;
        int value;
        
        Node(int key, int value) : key(key), value(value) {}
    };
    
    Node *root = nullptr;
    
    Node *tail = nullptr;
    
    unordered_map<int, Node*> hashmap;
    
    int capacity;
    
    void update_root(Node *node) {
        Node *tmp = root;
        if (tail == nullptr) {
            tail = node;
        } else if (tail == node) {
            tail = node;
            
            if (node->left != nullptr) {
                tail = node->left;
            }
        }
        
        if (root == nullptr) {
            root = node;
            tmp = root;
            return;
        }

        if (root != node) {
            Node *t = node->left;
            if (t != nullptr) {
                t->right = node->right;
                if (node->right != nullptr) {
                    node->right->left = t;
                }
            }
            
            node->right = root;
            root->left = node;
            root = node;
        }
    }
    
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if (hashmap.count(key) == 0) {
            return -1;
        } else {
            Node *node = hashmap[key];
            
            update_root(node);
            
            return root->value;
        }
    }
    
    void put(int key, int value) {
        if ((int) hashmap.size() == capacity && hashmap.count(key) == 0) {
            hashmap.erase(tail->key);
            Node *new_tail = nullptr;
            if (tail->left != nullptr) {
                new_tail = tail->left;
            }
            tail->left = nullptr;
            tail = nullptr;
            
            tail = new_tail;
            if (tail != nullptr) {
                tail->right = nullptr;
            }
        }
        
        Node *node;
        if (hashmap.count(key) == 0) {
            node = new Node(key, value);
        } else {
            node = hashmap[key];
        }
        node->value = value;
        
        hashmap[key] = node;
        update_root(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */