class LRUCache {
public:
    class node{
        public:
        int key;
        int value;
        node* next;
        node* prev;
        node(int _key, int _value){
            key = _key;
            value = _value;
        }
    };
    
    
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
        
    int cap;
    unordered_map<int, node*> map;
    
    LRUCache(int capacity) {
        //this is the initial condition when we had just 2 nodes ie. head and tail
        //initially the next of head is always pointing at tail
        //and the prev of tail is always pointing towards the head
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node* newnode){
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key_) {
        if(map.find(key_) != map.end()){
            node* resnode = map[key_];
            int res = resnode->value;
            
            map.erase(key_);
            deletenode(resnode); //delete that node 
            addnode(resnode); //add that new node just after the head
            map[key_] = head->next; //assign new address value to the key_
            return res;
        }
        return -1;
    } 
    
    void put(int key_, int value_) {
        //there are two cases 
        
        //if the key exists previously
        if(map.find(key_) != map.end()){
            node* existingnode = map[key_];
            map.erase(key_);
            deletenode(existingnode); //we have to delete it beacuse it have become the most             //recently used
        }
        
        //if m size is equal to capicity we need to remove the LRU cache that is the 
        //node just before the tail
        if(map.size()==cap){
            map.erase(tail->prev->key);
            deletenode(tail->prev);
        }   
        
        //after performing the above two steps now we have to insert our new node just 
        //just after the head
        addnode(new node(key_, value_));
        map[key_] = head->next;
        
    }
};

/*
add some more important comments tomorrow
*/ 

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
