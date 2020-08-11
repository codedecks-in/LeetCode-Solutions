/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        
        if (head == null){
            return false;
        }
        
        ListNode slowPtr = head;
        ListNode fastPtr = head;
        
        /** Approach
        
        // 1. if no cycle exists AND
            // a. if there are even number of nodes then fast pointer will be pointing to null.
            // b. else there are odd number of nodes then fast pointer will be pointing to last node.
        
        // 2. if slow pointer meet fast pointer that interprets there exists a loop 
        */
        
        while (fastPtr != null && fastPtr.next != null) {
            
            // move slow pointer one node at a time
            slowPtr = slowPtr.next;
            
            // move fast pointer two nodes at a time
            fastPtr = fastPtr.next.next;
            
            if (slowPtr == fastPtr)
                return true;
        }
        
        return false;
    }
}
