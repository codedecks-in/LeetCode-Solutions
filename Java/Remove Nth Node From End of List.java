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
        // If the list is already empty.....
        if(head == null){
            return head;
        }
        // Calculating the Length of The Linked list......... 
        ListNode temp = head;
        int count = 0;
        while(temp!=null){
            
            count++;
            temp = temp.next;
        }
        //System.out.println(count);
        if(n == count){
            head = head.next;
        }
        int counter = 0;
        int num = count- n;
        temp = head;
        while(temp != null && temp.next != null){
            counter++;
            if(counter == num){
                temp.next = temp.next.next;
            }
            else{
                temp = temp.next;
            }
        }
        return head;
    }
}
