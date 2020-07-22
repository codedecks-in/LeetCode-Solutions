/**
* LRU Cache
*
* Logic : maintain doubly linked List for insertion at head and deletion from tail and maintain       		  hashmap of key as key and value as node. Node consists of key, value, prev and next  	    		  pointers.
* Runtime: 16 ms
* Memory Usage: 47.9 MB
*/

class LRUCache {

    final Node head = new Node();
    final Node tail = new Node();
    int capacity;
    Map<Integer, Node> map;
    
    public LRUCache(int capacity) {
        map = new HashMap(capacity);
        this.capacity = capacity;
        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int key) {
        int result =  -1;
        Node node = map.get(key);
        if(node!=null)
        {
            remove(node);
            add(node);
            result = node.val;
        }
        return result;
    }
    
    public void put(int key, int value) {
        Node node = map.get(key);
        if(node!=null)
        {
            remove(node);
            node.val = value;
            add(node);
        }
        else{
            if(map.size() == capacity)
            {
                map.remove(tail.prev.key);
                remove(tail.prev);
            }
            Node new_node = new Node();
            
            new_node.key = key;
            new_node.val = value;
            map.put(key, new_node);
            add(new_node);
        }
    }
    
    public void add(Node node)
    {
        Node head_next = head.next;
        node.next = head_next;
        head_next.prev = node;
        head.next = node;
        node.prev = head;
        
    }
    
    public void remove(Node node)
    {
        Node next_node = node.next;
        Node prev_node = node.prev;
        
        next_node.prev = prev_node;
        prev_node.next = next_node;
        
    }
    
    class Node{
        int key;
        int val;
        Node prev;
        Node next;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
