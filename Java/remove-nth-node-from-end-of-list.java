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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode slow = head, fast = head, prev = null;
        // move one ptr such that it points to nth node from start of Linked List
        while(n-->1)
            fast = fast.next;
        
        // now move the second ptr as long as first ptr doesn't point to last node
        while(fast.next!=null){
            prev = slow;
            slow = slow.next;
            fast = fast.next;
        }
        
        // if the nth node from end is the start node of list
        if(prev==null)
            head = head.next;
        else
            prev.next = slow.next;
        
        return head;
    }
}