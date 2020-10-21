class ListNode(object):
    def __init__(self,key,val):
        self.key = key
        self.value  = val
        self.next = None
        self.prev  = None

class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.dic = {}
        self.head = ListNode(-1,-1)
        self.tail = ListNode(-1,-1)
        self.head.next = self.tail
        self.tail.prev = self.head
        

    def get(self, key: int) -> int:
        if key in self.dic:
            node = self.dic[key]
            self.remove(node)
            self.add(node)
            return node.value
        return -1

    def put(self, key: int, value: int) -> None:
    
        if key in self.dic:
            node = self.dic[key]
            self.remove(node)
            del self.dic[node.key]
        if len(self.dic)>=self.cap:
            node = self.head.next
            self.remove(node)
            del self.dic[node.key]
            
        node = ListNode(key,value)
        self.dic[key] = node
        self.add(node)
        # self.show(self.head)
        
        
    
    def remove(self,node):
        prevNode = node.prev
        prevNode.next = node.next
        node.next.prev = prevNode
        
    def add(self,node):
        tailprev = self.tail.prev
        tailprev.next = node
        node.prev = tailprev
        node.next = self.tail
        self.tail.prev = node
        # self.show(self.head)
        
    def show(self,head):
        while head:
            print(head.value,end=" ")
            head = head.next
        print()
            


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
