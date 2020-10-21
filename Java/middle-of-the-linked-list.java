/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode currentNode = head;
        
        ListNode slowPtr = head;
        ListNode fastPtr = head;
        
        while(fastPtr != null && fastPtr.next != null){
            slowPtr = slowPtr.next; // slow pointer will move 1 node at a time
            fastPtr = fastPtr.next.next; // fast pointer will move 2 nodes at a time
        }
        
        // at end slow pointer will be pointing to middle node
        return slowPtr;
    }
}
