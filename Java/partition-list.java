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
    public ListNode partition(ListNode head, int x) {
        
        ListNode smallHead=new ListNode(0);
        ListNode bigHead=new ListNode(0);
        
        ListNode small=smallHead;
        ListNode big=bigHead;
        
        while(head!=null)
        {
            if(head.val<x)
            {
                small.next=head;
                small=small.next;
            }
            else
            {
                big.next=head;
                big=big.next;
            }
            head=head.next;
        }
        big.next=null;
        small.next=bigHead.next;
        
        return smallHead.next;
    }
}