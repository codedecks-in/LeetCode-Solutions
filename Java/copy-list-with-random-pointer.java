/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    Node resultHead;
    Node resultTail;
    
    // function that gets the node at the given index: idx
    public Node getIndex (Node curr, int idx) {
        // if the value of idx is zero then the current node is the correct indexed node
        if (idx == 0) 
            return curr;
        
        // steps forward and decrements the idx at once, so that idx would be reached
        return getIndex (curr.next, idx -= 1);
    }
    
    // function that appends Node at the end of the linked-list
    public void appendList (int val) {
        // if both head and tail are null then linked list is empty
        if (this.resultHead == null && this.resultTail == null) {
            this.resultHead = new Node (val);
            this.resultTail = this.resultHead;
        // else uses tail for O(n) operations
        } else {
            this.resultTail.next = new Node (val);
            this.resultTail = this.resultTail.next;
        }
    }
    
    // solution function
    public Node copyRandomList (Node head) {
        this.resultHead = null;
        this.resultTail = null;
        
        List <Node> idxs = new ArrayList <> ();
        Node curr = head;

        // create the normal linked list without any random pointers, simultaneously add the node to an ArrayList so that we could index into the node
        while (curr != null) {
            idxs.add (curr);
            appendList (curr.val);
            
            curr = curr.next;
        }
        
        curr = this.resultHead;
        for (int i = 0; i < idxs.size (); i += 1) {
            int idx = -1;
            // get the value of idx using indexOf::LinkedList 
            if (idxs.get (i).random != null)
                idx = idxs.indexOf (idxs.get (i).random);
            
            // idx will be -1 if the random value is null
            if (idx == -1)
                curr.random = null;
            else 
            // else it will use the getIndex method to get the node at the given index
                curr.random = getIndex (this.resultHead, idx);
            
            curr = curr.next;
        }
        
        return this.resultHead;
    }
}
