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
    
    public ListNode detectCycle(ListNode head) {
        
        if(head == null){
            return null;
        }
        
        ListNode slowPtr = isCycleExists(head);
        ListNode fastPtr = head;
        
        if(slowPtr != null){
            while(fastPtr != slowPtr){
                fastPtr = fastPtr.next;
                slowPtr = slowPtr.next;
            }
            return slowPtr;
        }
        
        return null;
    }
    
    public ListNode isCycleExists(ListNode head){
        ListNode currentHead = head;
        
        ListNode slowPtr = head;
        ListNode fastPtr = head;
        
        while (fastPtr != null && fastPtr.next != null) {
            slowPtr = slowPtr.next;
            fastPtr = fastPtr.next.next;

            if (slowPtr == fastPtr)
                return slowPtr;
        }
        
        return null;
    }
    
}
