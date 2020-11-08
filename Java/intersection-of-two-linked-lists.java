/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        
        int lenA = getLinkedListLength(headA);
        int lenB = getLinkedListLength(headB);
        
        ListNode head1 = headA;
        ListNode head2 = headB;
        
        if(lenA > lenB){
            int diff = lenA - lenB;
            head1 = moveList(diff, head1);
        }
        else{
            int diff = lenB - lenA;
            head2 = moveList(diff, head2);
        }
        
        while(head1 != null){
            if(head1 == head2){
                return head1;
            }
            else if(head1.next == head2.next){
                return head1.next;
            }
            head1 = head1.next;
            head2 = head2.next;
        }
        
        return null;
    }
    
    public int getLinkedListLength(ListNode head){
        ListNode currentHead = head;
        int len = 0;
        
        while(currentHead != null){
            currentHead = currentHead.next;
            len++;
        }
        
        return len;
    }
    
    public ListNode moveList(int difference, ListNode head){
        while(difference != 0){
                head = head.next;
                difference--;
            }
        return head;
    }
}
